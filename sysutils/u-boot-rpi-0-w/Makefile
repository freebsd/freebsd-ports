MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		rpi-0-w
BOARD_CONFIG=	rpi_0_w_defconfig
FAMILY=		rpi

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi_0_w_fragment
FRAGMENT_NAME=		rpi_0_w_fragment

.include "${MASTERDIR}/Makefile"
