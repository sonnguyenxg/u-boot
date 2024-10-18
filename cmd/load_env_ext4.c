#include <common.h>
#include <command.h>
#include <env.h>

int do_bootenv_ext4(struct cmd_tbl *cmdtp, int flag, int argc, char *const argv[]) {
    printf("Setting environment variables for getting environment files from ext4...\n");

    env_set("mmcpart", "2");
    env_set("loadbootenv", "ext4load mmc ${mmcdev}:${mmcpart} ${env_addr} ${fdtfile}");
    env_set("fdtfile", "boot/uEnv.txt");

    return 0;
}

// Register the command
U_BOOT_CMD(
    bootenv_ext4,
    1,
    1,
    do_bootenv_ext4,
    "Load environment from ext4 and set boot command",
    NULL
);
