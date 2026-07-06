PORTNAME=	cryptopp-modern
DISTVERSION=	2026.7.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/cryptopp-modern/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++ class library of cryptographic algorithms and schemes
WWW=		https://github.com/cryptopp-modern/cryptopp-modern

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing dos2unix pathfix zip

CMAKE_OFF=	CRYPTOPP_BUILD_TESTING

CMAKE_TESTING_ON=	CRYPTOPP_BUILD_TESTING

CONFLICTS_INSTALL=	cryptopp

.include <bsd.port.mk>
