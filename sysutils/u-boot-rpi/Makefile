MASTERDIR=	${.CURDIR}/../u-boot-master

PATCHFILES+=	939129/raw

MODEL=		rpi
BOARD_CONFIG=	rpi_defconfig
FAMILY=		rpi

U_BOOT_SLAVE_PORTREVISION_2021.04=	1

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi_fragment
FRAGMENT_NAME=		rpi_fragment

.include "${MASTERDIR}/Makefile"
