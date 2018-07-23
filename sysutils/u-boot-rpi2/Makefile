# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		rpi2
BOARD_CONFIG=	rpi_2_defconfig
FAMILY=		rpi

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

PATCHFILES+=	937869/mbox/?	\
		939129/mbox/?

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi2_fragment
FRAGMENT_NAME=	rpi2_fragment

.include "${MASTERDIR}/Makefile"
