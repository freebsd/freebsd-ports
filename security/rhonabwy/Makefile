PORTNAME=	rhonabwy
PORTVERSION=	1.1.11
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Javascript Object Signing and Encryption (JOSE) library
WWW=		https://babelouest.github.io/rhonabwy/ \
		https://github.com/babelouest/rhonabwy

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	jansson>=2.4:devel/jansson \
		orcania>=2.3.2:devel/orcania \
		ulfius>=2.7.13:www/ulfius \
		yder>=1.4.19:devel/yder
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libjansson.so:devel/jansson \
		libnettle.so:security/nettle \
		liborcania.so:devel/orcania \
		libulfius.so:www/ulfius \
		libyder.so:devel/yder

USES=		cmake pathfix pkgconfig

CMAKE_OFF=	BUILD_RHONABWY_DOCUMENTATION BUILD_RHONABWY_TESTING BUILD_RPM DOWNLOAD_DEPENDENCIES
CMAKE_ON=	BUILD_RNBYC BUILD_STATIC INSTALL_HEADER SEARCH_ORCANIA_R SEARCH_YDER_R WITH_CURL WITH_ULFIUS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/librhonabwy.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
