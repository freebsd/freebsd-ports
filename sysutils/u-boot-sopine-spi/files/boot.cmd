sf probe
sf erase 0 0x100000
fatload mmc 0 ${kernel_addr_r} u-boot-sunxi-with-spl.bin
sf write ${kernel_addr_r} 0 0x100000
echo "Flash programmed"
while true; do
sleep 1
done
