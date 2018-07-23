# $FreeBSD$

MAINTAINER=	uboot@FreeBSD.org
MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		rpi3
BOARD_CONFIG=	rpi_3_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

EXTRA_PATCHES=	${.CURDIR}/files/
PATCHFILES+=	937869/mbox/?	\
		939129/mbox/?

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi3_fragment
FRAGMENT_NAME=	rpi3_fragment

.include "${MASTERDIR}/Makefile"
