MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2023.10=	1

WWW=		https://wiki.freebsd.org/FreeBSD/arm/Raspberry%20Pi

PATCHFILES+=	1838641/raw

MODEL=		rpi2
BOARD_CONFIG=	rpi_2_defconfig
FAMILY=		rpi

DEPENDS=	${LOCALBASE}/share/rpi-firmware/bootcode.bin:sysutils/rpi-firmware

CONFIG_FRAGMENT=	${.CURDIR}/files/rpi2_fragment
FRAGMENT_NAME=	rpi2_fragment

.include "${MASTERDIR}/Makefile"
