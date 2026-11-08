PORTNAME=	solr
PORTVERSION=	2.9.3
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	gaod@hychen.org
COMMENT=	PHP extension for Apache Solr
WWW=		https://github.com/php/pecl-search_engine-solr

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gnome php:ext pkgconfig
USE_GNOME=	libxml2
IGNORE_WITH_PHP=	86
USE_GITHUB=	yes
GH_ACCOUNT=	php
GH_PROJECT= 	pecl-search_engine-solr

CONFIGURE_ARGS=	LIBXML_CFLAGS=-I${LOCALBASE}/include/libxml2 \
		LIBXML_LIBS=-L${LOCALBASE}/include/libxml2

.include <bsd.port.mk>
