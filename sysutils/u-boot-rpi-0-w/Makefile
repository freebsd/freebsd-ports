MASTERDIR=	${.CURDIR}/../u-boot-master

PATCHFILES+=	939129/raw

MODEL=		rpi-0-w
BOARD_CONFIG=	rpi_0_w_defconfig
FAMILY=		rpi

U_BOOT_SLAVE_PORTREVISION_2021.04=	1

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi_0_w_fragment
FRAGMENT_NAME=		rpi_0_w_fragment

.include "${MASTERDIR}/Makefile"
