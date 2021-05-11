MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		wandboard
BOARD_CONFIG=	wandboard_defconfig
FAMILY=		imx6

U_BOOT_SLAVE_PORTREVISION_2021.04=	1

IMXFILE=	u-boot.imx
UBOOT_PLIST=	${IMXFILE}

ALL_TARGET=	u-boot-with-spl.imx

pre-install: .PHONY
	@${CP} ${WRKSRC}/u-boot-with-spl.imx ${WRKSRC}/${IMXFILE}

.include "${MASTERDIR}/Makefile"
