PORTNAME=	cryptopp-modern
DISTVERSION=	2026.8.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/cryptopp-modern/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++ class library of cryptographic algorithms and schemes
WWW=		https://github.com/cryptopp-modern/cryptopp-modern

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing dos2unix pathfix
USE_LDCONFIG=	yes

CMAKE_ON=	CRYPTOPP_BUILD_SHARED
CMAKE_OFF=	CRYPTOPP_BUILD_TESTING
CMAKE_TESTING_ON=	CRYPTOPP_BUILD_TESTING

CONFLICTS_INSTALL=	cryptopp

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

TOOLS_DESC=	Install encryption/decryption tools

TOOLS_CMAKE_BOOL=	CRYPTOPP_INSTALL_CRYPTEST

post-install-TOOLS-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/cryptest.exe ${STAGEDIR}${PREFIX}/bin/cryptest

.include <bsd.port.mk>
