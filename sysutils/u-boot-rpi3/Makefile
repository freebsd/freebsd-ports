# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

EXTRA_PATCHES=	${.CURDIR}/files/
PATCHFILES+=	939129/raw
# Allow variable reservation of lowest pages for increased PSCI stub size.
PATCHFILES+=	1245351/raw 1245352/raw

MODEL=		rpi3
BOARD_CONFIG=	rpi_3_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi3_fragment
FRAGMENT_NAME=	rpi3_fragment

.include "${MASTERDIR}/Makefile"
