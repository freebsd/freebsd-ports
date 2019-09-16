# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2019.07=	1

MODEL=		beaglebone
BOARD_CONFIG=	am335x_evm_defconfig
FAMILY=		omap

CONFIG_FRAGMENT=	${.CURDIR}/files/bbb_fragment
FRAGMENT_NAME=		bbb_fragment

.include "${MASTERDIR}/Makefile"
