fatload ${devtype} ${devnum}:${distro_bootpart} ${kernel_addr_r} ubldr.bin && go ${kernel_addr_r}
echo "Cannot load ubldr.bin"
