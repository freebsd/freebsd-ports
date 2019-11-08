# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

EXTRA_PATCHES=	${.CURDIR}/files/
PATCHFILES+=	939129/raw
# Updated libfdt, pre-req to the next set
PATCHFILES+=	1137331/raw 1137330/raw
# Fix memory bank issues
PATCHFILES+=	1189494/raw 1189493/raw 1189497/raw 1189495/raw

MODEL=		rpi4
BOARD_CONFIG=	rpi_4_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi4_fragment
FRAGMENT_NAME=	rpi4_fragment

.include "${MASTERDIR}/Makefile"
