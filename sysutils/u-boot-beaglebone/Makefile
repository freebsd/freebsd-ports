MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		beaglebone
BOARD_CONFIG=	am335x_evm_defconfig
FAMILY=		omap

U_BOOT_SLAVE_PORTREVISION_2021.04=	1

CONFIG_FRAGMENT=	${.CURDIR}/files/bbb_fragment
FRAGMENT_NAME=		bbb_fragment

.include "${MASTERDIR}/Makefile"
