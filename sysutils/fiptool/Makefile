PORTNAME=	fiptool
DISTVERSIONPREFIX=	lts-v
DISTVERSION=	2.14.11
CATEGORIES=	sysutils

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	Create and update Arm TF-A firmware image packages (FIP)
WWW=		https://trustedfirmware-a.readthedocs.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/license.rst

# TF-A's make helpers use GNU sed syntax; with base sed the toolchain
# detection fails and the build stops.
BUILD_DEPENDS=	gsed:textproc/gsed

USES=		gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	arm-trusted-firmware

MAKE_ARGS=	BUILD_STRING=${DISTVERSIONFULL} \
		HOSTCC="${CC}" \
		HOSTCCFLAGS="${CFLAGS}" \
		OPENSSL_DIR=${OPENSSLBASE} \
		V=1
ALL_TARGET=	fiptool

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PLIST_FILES=	bin/fiptool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fiptool/fiptool \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
