--- include/configs/am335x_evm.h.orig	2013-04-19 09:25:43.000000000 -0500
+++ include/configs/am335x_evm.h	2013-05-16 17:08:37.000000000 -0500
@@ -20,6 +20,12 @@
 
 #include <asm/arch/omap.h>
 
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_CMD_ELF
+#define CONFIG_API
+#define CONFIG_SYS_MMC_MAX_DEVICE 2
+#endif
+
 #define CONFIG_DMA_COHERENT
 #define CONFIG_DMA_COHERENT_SIZE	(1 << 20)
 
@@ -53,94 +59,24 @@
 #define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
 #ifndef CONFIG_SPL_BUILD
 #define CONFIG_EXTRA_ENV_SETTINGS \
-	"loadaddr=0x80200000\0" \
-	"fdtaddr=0x80F80000\0" \
-	"fdt_high=0xffffffff\0" \
-	"rdaddr=0x81000000\0" \
-	"bootdir=/boot\0" \
-	"bootfile=uImage\0" \
+	"loadaddr=0x88000000\0" \
+	"fdtaddr=0x80000100\0" \
+	"bootfile=bbubldr\0" \
 	"fdtfile=\0" \
-	"console=ttyO0,115200n8\0" \
-	"optargs=\0" \
-	"mtdids=" MTDIDS_DEFAULT "\0" \
-	"mtdparts=" MTDPARTS_DEFAULT "\0" \
-	"dfu_alt_info_mmc=" DFU_ALT_INFO_MMC "\0" \
-	"dfu_alt_info_emmc=rawemmc mmc 0 3751936\0" \
-	"dfu_alt_info_nand=" DFU_ALT_INFO_NAND "\0" \
 	"mmcdev=0\0" \
-	"mmcroot=/dev/mmcblk0p2 ro\0" \
-	"mmcrootfstype=ext4 rootwait\0" \
-	"bootpart=0:2\0" \
-	"nandroot=ubi0:rootfs rw ubi.mtd=7,2048\0" \
-	"nandrootfstype=ubifs rootwait=1\0" \
-	"nandsrcaddr=0x280000\0" \
-	"nandimgsize=0x500000\0" \
-	"rootpath=/export/rootfs\0" \
-	"nfsopts=nolock\0" \
-	"static_ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}" \
-		"::off\0" \
-	"ramroot=/dev/ram0 rw ramdisk_size=65536 initrd=${rdaddr},64M\0" \
-	"ramrootfstype=ext2\0" \
-	"mmcargs=setenv bootargs console=${console} " \
-		"${optargs} " \
-		"root=${mmcroot} " \
-		"rootfstype=${mmcrootfstype}\0" \
-	"nandargs=setenv bootargs console=${console} " \
-		"${optargs} " \
-		"root=${nandroot} " \
-		"rootfstype=${nandrootfstype}\0" \
-	"spiroot=/dev/mtdblock4 rw\0" \
-	"spirootfstype=jffs2\0" \
-	"spisrcaddr=0xe0000\0" \
-	"spiimgsize=0x362000\0" \
-	"spibusno=0\0" \
-	"spiargs=setenv bootargs console=${console} " \
-		"${optargs} " \
-		"root=${spiroot} " \
-		"rootfstype=${spirootfstype}\0" \
-	"netargs=setenv bootargs console=${console} " \
-		"${optargs} " \
-		"root=/dev/nfs " \
-		"nfsroot=${serverip}:${rootpath},${nfsopts} rw " \
-		"ip=dhcp\0" \
-	"bootenv=uEnv.txt\0" \
-	"loadbootenv=load mmc ${mmcdev} ${loadaddr} ${bootenv}\0" \
+	"bootenv=bb-uEnv.txt\0" \
+	"loadbootenv=fatload mmc ${mmcdev} ${loadaddr} ${bootenv}\0" \
 	"importbootenv=echo Importing environment from mmc ...; " \
 		"env import -t $loadaddr $filesize\0" \
-	"ramargs=setenv bootargs console=${console} " \
-		"${optargs} " \
-		"root=${ramroot} " \
-		"rootfstype=${ramrootfstype}\0" \
-	"loadramdisk=load mmc ${mmcdev} ${rdaddr} ramdisk.gz\0" \
-	"loaduimage=load mmc ${bootpart} ${loadaddr} ${bootdir}/${bootfile}\0" \
-	"loadfdt=load mmc ${bootpart} ${fdtaddr} ${bootdir}/${fdtfile}\0" \
 	"mmcboot=echo Booting from mmc ...; " \
-		"run mmcargs; " \
-		"bootm ${loadaddr} - ${fdtaddr}\0" \
-	"nandboot=echo Booting from nand ...; " \
-		"run nandargs; " \
-		"nand read ${loadaddr} ${nandsrcaddr} ${nandimgsize}; " \
-		"bootm ${loadaddr}\0" \
-	"spiboot=echo Booting from spi ...; " \
-		"run spiargs; " \
-		"sf probe ${spibusno}:0; " \
-		"sf read ${loadaddr} ${spisrcaddr} ${spiimgsize}; " \
-		"bootm ${loadaddr}\0" \
-	"netboot=echo Booting from network ...; " \
-		"setenv autoload no; " \
-		"dhcp; " \
-		"tftp ${loadaddr} ${bootfile}; " \
-		"tftp ${fdtaddr} ${fdtfile}; " \
-		"run netargs; " \
-		"bootm ${loadaddr} - ${fdtaddr}\0" \
-	"ramboot=echo Booting from ramdisk ...; " \
-		"run ramargs; " \
-		"bootm ${loadaddr} ${rdaddr} ${fdtaddr}\0" \
+		"bootelf ${kloadaddr}\0" \
+	"loadfdt=fatload mmc ${mmcdev} ${fdtaddr} ${fdtfile};fdt addr ${fdtaddr}\0" \
+	"loadimage=fatload mmc ${mmcdev} ${loadaddr} ${bootfile}\0" \
 	"findfdt="\
 		"if test $board_name = A335BONE; then " \
-			"setenv fdtfile am335x-bone.dtb; fi; " \
+			"setenv fdtfile bbone.dtb; fi; " \
 		"if test $board_name = A335BNLT; then " \
-			"setenv fdtfile am335x-boneblack.dtb; fi; " \
+			"setenv fdtfile bboneblk.dtb; fi; " \
 		"if test $board_name = A33515BB; then " \
 			"setenv fdtfile am335x-evm.dtb; fi; " \
 		"if test $board_name = A335X_SK; then " \
@@ -160,12 +96,10 @@
 			"echo Running uenvcmd ...;" \
 			"run uenvcmd;" \
 		"fi;" \
-		"if run loaduimage; then " \
+		"if run loadimage; then " \
 			"run loadfdt;" \
 			"run mmcboot;" \
 		"fi;" \
-	"else " \
-		"run nandboot;" \
 	"fi;" \
 
 /* Clock Defines */
@@ -205,8 +139,6 @@
 #define CONFIG_DOS_PARTITION
 #define CONFIG_CMD_FAT
 #define CONFIG_FAT_WRITE
-#define CONFIG_CMD_EXT2
-#define CONFIG_CMD_EXT4
 #define CONFIG_CMD_FS_GENERIC
 
 #define CONFIG_SPI
@@ -230,7 +162,6 @@
 /* USB Device Firmware Update support */
 #define CONFIG_DFU_FUNCTION
 #define CONFIG_DFU_MMC
-#define CONFIG_DFU_NAND
 #define CONFIG_CMD_DFU
 #define DFU_ALT_INFO_MMC \
 	"boot part 0 1;" \
@@ -240,14 +171,6 @@
 	"u-boot.img.raw mmc 300 3C0;" \
 	"u-boot.img fat 0 1;" \
 	"uEnv.txt fat 0 1"
-#define DFU_ALT_INFO_NAND \
-	"SPL part 0 1;" \
-	"SPL.backup1 part 0 2;" \
-	"SPL.backup2 part 0 3;" \
-	"SPL.backup3 part 0 4;" \
-	"u-boot part 0 5;" \
-	"kernel part 0 7;" \
-	"rootfs part 0 8"
 
  /* Physical Memory Map */
 #define CONFIG_NR_DRAM_BANKS		1		/*  1 bank of DRAM */
@@ -313,7 +236,7 @@
 #define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR	0x300 /* address 0x60000 */
 #define CONFIG_SYS_U_BOOT_MAX_SIZE_SECTORS	0x200 /* 256 KB */
 #define CONFIG_SYS_MMC_SD_FAT_BOOT_PARTITION	1
-#define CONFIG_SPL_FAT_LOAD_PAYLOAD_NAME	"u-boot.img"
+#define CONFIG_SPL_FAT_LOAD_PAYLOAD_NAME	"bb-uboot.img"
 #define CONFIG_SPL_MMC_SUPPORT
 #define CONFIG_SPL_FAT_SUPPORT
 #define CONFIG_SPL_I2C_SUPPORT
@@ -323,51 +246,15 @@
 #define CONFIG_SPL_LIBGENERIC_SUPPORT
 #define CONFIG_SPL_SERIAL_SUPPORT
 #define CONFIG_SPL_GPIO_SUPPORT
-#define CONFIG_SPL_YMODEM_SUPPORT
-#define CONFIG_SPL_NET_SUPPORT
-#define CONFIG_SPL_NET_VCI_STRING	"AM335x U-Boot SPL"
-#define CONFIG_SPL_ETH_SUPPORT
 #define CONFIG_SPL_SPI_SUPPORT
 #define CONFIG_SPL_SPI_FLASH_SUPPORT
 #define CONFIG_SPL_SPI_LOAD
 #define CONFIG_SPL_SPI_BUS		0
 #define CONFIG_SPL_SPI_CS		0
 #define CONFIG_SYS_SPI_U_BOOT_OFFS	0x80000
-#define CONFIG_SPL_MUSB_NEW_SUPPORT
 #define CONFIG_SPL_LDSCRIPT		"$(CPUDIR)/am33xx/u-boot-spl.lds"
 
 #define CONFIG_SPL_BOARD_INIT
-#define CONFIG_SPL_NAND_AM33XX_BCH
-#define CONFIG_SPL_NAND_SUPPORT
-#define CONFIG_SPL_NAND_BASE
-#define CONFIG_SPL_NAND_DRIVERS
-#define CONFIG_SPL_NAND_ECC
-#define CONFIG_SYS_NAND_5_ADDR_CYCLE
-#define CONFIG_SYS_NAND_PAGE_COUNT	(CONFIG_SYS_NAND_BLOCK_SIZE / \
-					 CONFIG_SYS_NAND_PAGE_SIZE)
-#define CONFIG_SYS_NAND_PAGE_SIZE	2048
-#define CONFIG_SYS_NAND_OOBSIZE		64
-#define CONFIG_SYS_NAND_BLOCK_SIZE	(128*1024)
-#define CONFIG_SYS_NAND_BAD_BLOCK_POS	NAND_LARGE_BADBLOCK_POS
-#define CONFIG_SYS_NAND_ECCPOS		{ 2, 3, 4, 5, 6, 7, 8, 9, \
-					 10, 11, 12, 13, 14, 15, 16, 17, \
-					 18, 19, 20, 21, 22, 23, 24, 25, \
-					 26, 27, 28, 29, 30, 31, 32, 33, \
-					 34, 35, 36, 37, 38, 39, 40, 41, \
-					 42, 43, 44, 45, 46, 47, 48, 49, \
-					 50, 51, 52, 53, 54, 55, 56, 57, }
-
-#define CONFIG_SYS_NAND_ECCSIZE		512
-#define CONFIG_SYS_NAND_ECCBYTES	14
-
-#define CONFIG_SYS_NAND_ECCSTEPS	4
-#define	CONFIG_SYS_NAND_ECCTOTAL	(CONFIG_SYS_NAND_ECCBYTES * \
-						CONFIG_SYS_NAND_ECCSTEPS)
-
-#define	CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_TEXT_BASE
-
-#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x80000
-
 /*
  * 1MB into the SDRAM to allow for SPL's bss at the beginning of SDRAM
  * 64 bytes before this address should be set aside for u-boot.img's
@@ -462,7 +349,7 @@
 #define CONFIG_PHY_ADDR			0
 #define CONFIG_PHY_SMSC
 
-#define CONFIG_NAND
+#undef CONFIG_NAND
 /* NAND support */
 #ifdef CONFIG_NAND
 #define CONFIG_CMD_NAND
