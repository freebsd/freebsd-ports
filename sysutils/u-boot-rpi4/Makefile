MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2023.10=	1

EXTRA_PATCHES=	${.CURDIR}/files/
PATCHFILES+=	1838641/raw

MODEL=		rpi4
BOARD_CONFIG=	rpi_4_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi4_fragment
FRAGMENT_NAME=	rpi4_fragment

.include "${MASTERDIR}/Makefile"
