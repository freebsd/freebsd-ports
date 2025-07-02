PORTNAME=	solr
PORTVERSION=	2.7.0
CATEGORIES=	www

MAINTAINER=	gaod@hychen.org
COMMENT=	PHP extension for Apache Solr
WWW=		https://pecl.php.net/package/solr

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gnome php:build,pecl pkgconfig
USE_GNOME=	libxml2
IGNORE_WITH_PHP=	84 85

CONFIGURE_ARGS=	LIBXML_CFLAGS=-I${LOCALBASE}/include/libxml2 \
		LIBXML_LIBS=-L${LOCALBASE}/include/libxml2

.include <bsd.port.mk>
