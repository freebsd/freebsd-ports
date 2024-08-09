PORTNAME=	libpsl-native
DISTVERSIONPREFIX=      v
DISTVERSION=	7.4.0
CATEGORIES=	shells

COMMENT=	libpsl-native provides native functions for powershell

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	PowerShell
GH_PROJECT=	PowerShell-Native

USES=	cmake

WRKSRC_SUBDIR=  src/libpsl-native

do-install:
	${INSTALL_LIB} ${WRKSRC}/../..//src/powershell-unix/libpsl-native.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
