# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		sopine-spi
BOARD_CONFIG=	sopine_baseboard_defconfig
FAMILY=		allwinner64

CONFIG_FRAGMENT=	${.CURDIR}/../u-boot-sopine-spi/files/spi_fragment
FRAGMENT_NAME=		spi_fragment
NO_METADATA=		yes
UBOOT_PLIST=		u-boot-sunxi-with-spl.bin \
			boot.scr
PLIST_EXTRAS=		sopine-spi-flasher.img

post-build:
	mkimage -C none -A arm64 -T script -d ${.CURDIR}/../u-boot-sopine-spi/files/boot.cmd ${WRKSRC}/boot.scr

post-stage:
	makefs -t msdos -s 5m ${WRKDIR}/sopine-spi-flash.msdos ${STAGEDIR}/${INST}
	mkimg -v -s mbr -p fat32::5M:1M -o ${STAGEDIR}/${INST}/sopine-spi-flasher.img
	dd if=${WRKDIR}/sopine-spi-flash.msdos of=${STAGEDIR}/${INST}/sopine-spi-flasher.img bs=1M oseek=1 conv=notrunc
	dd if=${STAGEDIR}/${INST}/u-boot-sunxi-with-spl.bin of=${STAGEDIR}/${INST}/sopine-spi-flasher.img bs=1k oseek=8 conv=notrunc

.include "${MASTERDIR}/Makefile"
