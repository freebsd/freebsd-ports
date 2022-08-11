PORTNAME=	solr
PORTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	gaod@hychen.org
COMMENT=	PHP extension for Apache Solr

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

USES=		php:pecl
USE_PHP=	json:build

CONFIGURE_ARGS=	LIBXML_CFLAGS=-I${LOCALBASE}/include/libxml2 \
		LIBXML_LIBS=-L${LOCALBASE}/include/libxml2

.include <bsd.port.mk>
