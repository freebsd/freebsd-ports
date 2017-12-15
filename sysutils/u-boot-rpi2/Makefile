# $FreeBSD$

MAINTAINER=	manu@FreeBSD.org
MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		rpi2
BOARD_CONFIG=	rpi_2_defconfig
FAMILY=		rpi

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

.include "${MASTERDIR}/Makefile"
