MASTERDIR=	${.CURDIR}/../u-boot-master

WWW=		https://wiki.freebsd.org/FreeBSD/arm/Raspberry%20Pi

MODEL=		rpi
BOARD_CONFIG=	rpi_defconfig
FAMILY=		rpi

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi_fragment
FRAGMENT_NAME=		rpi_fragment

.include "${MASTERDIR}/Makefile"
