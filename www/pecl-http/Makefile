PORTNAME=	http
PORTVERSION=	4.2.4
PORTREVISION=	1
CATEGORIES=	www
DISTNAME=	pecl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extended HTTP Support
WWW=		https://pecl.php.net/package/pecl_http

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2@${PHP_FLAVOR} \
		re2c:devel/re2c \
		bash>0:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libicudata.so:devel/icu
RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2@${PHP_FLAVOR}

USES=		php:build,pecl
USE_PHP=	iconv:build zlib:build

CONFIGURE_SHELL=	${LOCALBASE}/bin/bash

.include <bsd.port.mk>
