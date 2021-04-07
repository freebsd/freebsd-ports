MASTERDIR=	${.CURDIR}/../u-boot-master

EXTRA_PATCHES=	${.CURDIR}/files/
PATCHFILES+=	939129/raw

MODEL=		rpi-arm64
BOARD_CONFIG=	rpi_arm64_defconfig
FAMILY=		rpi
UBOOT_ARCH=	aarch64

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi_arm64_fragment
FRAGMENT_NAME=	rpi_arm64_fragment

.include "${MASTERDIR}/Makefile"
