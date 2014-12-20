# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2013.01
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-rpi
DISTNAME=	u-boot-${PORTVERSION}-${GH_ACCOUNT}-${GH_PROJECT}

MAINTAINER=	ian@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Raspberry Pi

LICENSE=	GPLv2

BUILD_DEPENDS=  arm-none-eabi-gcc:${PORTSDIR}/devel/arm-none-eabi-gcc \
		gsed:${PORTSDIR}/textproc/gsed

USE_GITHUB=	yes
GH_ACCOUNT=	gonzoua
GH_PROJECT=	u-boot-pi
GH_COMMIT=	6709570
GH_TAGNAME=	${GH_COMMIT}

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}
USES=		gmake
SSP_UNSAFE=	yes # cross-build static linking dies with -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/uboot.img \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi- \
		HOSTCC=cc \
		SED=gsed

do-configure:
	(cd ${WRKSRC}; ${GMAKE} ${MAKE_ARGS} rpi_b_config)

# The output of the u-boot build process is u-boot.bin.  We have to put a
# standard (for the RPi) image header on the front of it, and the resulting
# file is named uboot.img (without a dash for historical reasons).
IMGFILE=${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/uboot.img
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${GZCAT} ${FILESDIR}/imgprefix.bin.gz >${IMGFILE}
	${CAT} ${WRKSRC}/u-boot.bin >>${IMGFILE}
	${CP} ${.CURDIR}/pkg-descr ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
