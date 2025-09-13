PORTNAME=	iddawc
PORTVERSION=	1.1.8
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OAuth2/OIDC Client and Relying Party library
WWW=		https://babelouest.github.io/iddawc/ \
		https://github.com/babelouest/iddawc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream repo archived on Nov 11, 2024
EXPIRATION_DATE=2024-10-13

BUILD_DEPENDS=	jansson>=2.11:devel/jansson \
		orcania>=2.3.2:devel/orcania \
		rhonabwy>=1.1.10:security/rhonabwy \
		ulfius>=2.7.12:www/ulfius \
		yder>=1.4.14:devel/yder
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgnutls.so:security/gnutls \
		libjansson.so:devel/jansson \
		libmicrohttpd.so:www/libmicrohttpd \
		liborcania.so:devel/orcania \
		librhonabwy.so:security/rhonabwy \
		libulfius.so:www/ulfius \
		libyder.so:devel/yder

USES=		cmake pathfix

CMAKE_OFF=	BUILD_IDDAWC_DOCUMENTATION BUILD_IDDAWC_TESTING BUILD_RPM DOWNLOAD_DEPENDENCIES
CMAKE_ON=	BUILD_IDWCC BUILD_STATIC INSTALL_HEADER SEARCH_ORCANIA_I SEARCH_RHONABWY_I SEARCH_ULFIUS_I SEARCH_YDER_I

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libiddawc.a ${STAGEDIR}${PREFIX}/lib/libiddawc.a

.include <bsd.port.mk>
