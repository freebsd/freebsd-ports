MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2021.07=	1

EXTRA_PATCHES=	${.CURDIR}/files/
PATCHFILES+=	939129/raw \
		1547145/raw

MODEL=		rpi4
BOARD_CONFIG=	rpi_4_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi4_fragment
FRAGMENT_NAME=	rpi4_fragment

.include "${MASTERDIR}/Makefile"
