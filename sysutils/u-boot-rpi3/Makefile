# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		rpi3
BOARD_CONFIG=	rpi_3_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

FRAGMENT_NAME=		rpi3_fragment
CONFIG_FRAGMENT=	${.CURDIR}/files/${FRAGMENT_NAME}

.include "${MASTERDIR}/Makefile"
