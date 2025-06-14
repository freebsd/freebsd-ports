PORTNAME=	u-boot-tools
DISTVERSION=	2025.10 # Keep in sync with sysutils/u-boot-master
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
DISTNAME=	u-boot-${PORTVERSION}

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	U-boot related tools
WWW=		https://www.denx.de/wiki/U-Boot

LICENSE=	GPLv2

ALL_TARGET=	tools-only_defconfig tools-only
USES=		bison compiler:c11 gmake pkgconfig python:build tar:bzip2

BUILD_DEPENDS=	gdate:sysutils/coreutils
LIB_DEPENDS=	libgnutls.so:security/gnutls

MAKE_ARGS=	ARCH=sandbox \
		CC="${CC}" \
		HOSTCC="${CC}" \
		KBUILD_VERBOSE=1

PLIST_FILES=	bin/mkimage bin/mkenvimage bin/dumpimage bin/fit_info
BINARY_ALIAS=	python3=${PYTHON_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/dumpimage ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fit_info ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkenvimage ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkimage ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
