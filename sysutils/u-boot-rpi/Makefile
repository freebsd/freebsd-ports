# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		rpi
BOARD_CONFIG=	rpi_defconfig
FAMILY=		rpi

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

FRAGMENT_NAME=		rpi_fragment
CONFIG_FRAGMENT=	${.CURDIR}/files/${FRAGMENT_NAME}

.include "${MASTERDIR}/Makefile"
