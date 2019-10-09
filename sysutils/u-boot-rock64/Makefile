# $FreeBSD$

MASTERDIR=	${.CURDIR}/../u-boot-master

U_BOOT_SLAVE_PORTREVISION_2019.10=	1

PATCHFILES+=	1173473/raw \
		1172554/raw \
		1172555/raw

MODEL=		rock64
BOARD_CONFIG=	rock64-rk3328_defconfig
FAMILY=		rk3328

UBOOT_EXTRA_TARGETS=	u-boot.itb

.include "${MASTERDIR}/Makefile"
