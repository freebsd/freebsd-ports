# Created by: Derek Schrock <dereks@lifeofadishwasher.com>

PORTNAME=	xmlrpc
PORTVERSION=	1.0.0
DISTVERSIONSUFFIX=	RC2
CATEGORIES=	net pear

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	PHP extension for XML-RPC servers and clients

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		iconv:translit gnome php:pecl pkgconfig
USE_PHP=	xml:build
USE_GNOME=	libxml2
IGNORE_WITH_PHP=	74 81

CONFIGURE_ARGS+=	--with-iconv-dir=${LOCALBASE}

TEST_TARGET=	test
TEST_ENV=	NO_INTERACTION=yes

.include <bsd.port.mk>
