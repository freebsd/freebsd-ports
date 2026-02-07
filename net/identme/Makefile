PORTNAME=	identme
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	net

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Simple CLI for retrieving your public IP address
WWW=		https://github.com/pcarrier/ident.me \
		https://www.ident.me

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c++17-lang
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	pcarrier
GH_PROJECT=	ident.me

CMAKE_SOURCE_PATH=	${WRKSRC}/cli
LDFLAGS+=	-lpthread

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
