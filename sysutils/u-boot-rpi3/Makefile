# $FreeBSD$

MAINTAINER=	uboot@FreeBSD.org
MASTERDIR=	${.CURDIR}/../u-boot-master
PORTREVISION=	1

MODEL=		rpi3
BOARD_CONFIG=	rpi_3_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

EXTRA_PATCHES=	${.CURDIR}/files/

.include "${MASTERDIR}/Makefile"
