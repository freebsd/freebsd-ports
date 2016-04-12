# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2013.10
PORTREVISION=	2
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-wandboard

MAINTAINER=	ian@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Wandboard (solo, dual, and quad)

LICENSE=	GPLv2

BUILD_DEPENDS=	${CROSS_GCC}:devel/arm-none-eabi-gcc492

CROSS_GCC=	arm-none-eabi-gcc-4.9.2

USE_GITHUB=	yes
GH_ACCOUNT=	TechNexion
GH_PROJECT=	u-boot-edm
GH_TAGNAME=	87f595d
NO_ARCH=	yes

USES=		gmake
SSP_UNSAFE=	yes # cross-build static linking dies with -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.imx \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CC=${CROSS_GCC} \
		CROSS_COMPILE=arm-none-eabi- \
		HOSTCC=cc

do-configure:
	cd ${WRKSRC}; ${GMAKE} ${MAKE_ARGS} edm_cf_imx6_config

# The build results in two output files: SPL, and u-boot.img.
# Combine them into a single u-boot.imx so that there is only one file to be
# copied onto the boot media starting at a 1K offset on the disk.
IMXFILE=	${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/u-boot.imx
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	dd bs=1k oseek=0  conv=sync of=${IMXFILE} if=${WRKSRC}/SPL
	dd bs=1k oseek=68 conv=sync of=${IMXFILE} if=${WRKSRC}/u-boot.img
	${CP} ${.CURDIR}/pkg-descr ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
