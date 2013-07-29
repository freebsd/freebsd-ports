# $FreeBSD$

PORTNAME=	beaglebone
PORTVERSION=	2013.04
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kientzle
PKGNAMEPREFIX=	u-boot-
PKGNAMESUFFIX=	-eabi
DISTNAME=	u-boot-2013.04

MAINTAINER=	kientzle@FreeBSD.org
COMMENT=	U-Boot loader for BeagleBone and BeagleBone Black

BUILD_DEPENDS=	arm-eabi-gcc:${PORTSDIR}/devel/arm-eabi-gcc

WRKSRC=		${WRKDIR}/u-boot-${PORTVERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/bb-uboot.img \
		${U_BOOT_DIR}/bb-uenv.txt \
		${U_BOOT_DIR}/MLO \
		${U_BOOT_DIR}/README
PLIST_DIRS=	${U_BOOT_DIR} share/u-boot

CROSS_PREFIX=	arm-eabi-
ARCH=		arm

do-configure:
	(cd ${WRKSRC}; ${GMAKE} CROSS_COMPILE=${CROSS_PREFIX} am335x_evm_config)

do-build:
	(cd ${WRKSRC};${GMAKE} CROSS_COMPILE=${CROSS_PREFIX} )

do-install:
	${MKDIR} ${PREFIX}/${U_BOOT_DIR}
	${CP} ${WRKSRC}/MLO ${PREFIX}/${U_BOOT_DIR}
	${CP} ${WRKSRC}/u-boot.img ${PREFIX}/${U_BOOT_DIR}/bb-uboot.img
	${TOUCH} ${PREFIX}/${U_BOOT_DIR}/bb-uenv.txt
	${CP} ${.CURDIR}/pkg-descr ${PREFIX}/${U_BOOT_DIR}/README

post-install:
	${ECHO_CMD} U-Boot files are installed in ${U_BOOT_DIR}.

.include <bsd.port.mk>
