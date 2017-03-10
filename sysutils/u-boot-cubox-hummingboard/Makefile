# $FreeBSD$

MAINTAINER=	imp@FreeBSD.org
MASTERDIR=	${.CURDIR}/../u-boot-master

MODEL=		cubox-hummingboard
BOARD_CONFIG=	mx6cuboxi_defconfig
FAMILY=		imx6

IMXFILE=	u-boot.imx
UBOOT_PLIST=	${IMXFILE}

ALL_TARGET=	u-boot-with-spl.imx

pre-install: .PHONY
	@${CP} ${WRKSRC}/u-boot-with-spl.imx ${WRKSRC}/${IMXFILE}

<<<<<<< HEAD
USE_GITHUB=	yes
GH_ACCOUNT=	SolidRun
GH_PROJECT=	u-boot-imx6
GH_TAGNAME=	e4bc4c3

NOPIE_PORTS=	yes
NORELRO_PORTS=	yes

NO_ARCH=	yes

USES=		gmake
SSP_UNSAFE=	yes # cross-build static linking dies with -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_DIRS=	${U_BOOT_DIR} share/u-boot
PLIST_FILES=	${U_BOOT_DIR}/u-boot.imx \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CC=${CROSS_GCC} \
		CROSS_COMPILE=arm-none-eabi- \
		HOSTCC=cc

do-configure:
	cd ${WRKSRC}; ${MAKE_CMD} ${MAKE_ARGS} mx6_cubox-i_config

# The build results in two output files: SPL, and u-boot.img.
# Combine them into a single u-boot.imx so that there is only one file to be
# copied onto the boot media starting at a 1K offset on the disk.
IMXFILE=	${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/u-boot.imx
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	dd bs=1k oseek=0  conv=sync of=${IMXFILE} if=${WRKSRC}/SPL
	dd bs=1k oseek=41 conv=sync of=${IMXFILE} if=${WRKSRC}/u-boot.img
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
=======
.include "${MASTERDIR}/Makefile"
>>>>>>> upstream/master
