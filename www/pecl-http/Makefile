# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	http
PORTVERSION=	4.2.0
CATEGORIES=	www
DISTNAME=	pecl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extended HTTP Support

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# For now UNBREAK for mips while being updated.
#BROKEN_mips=	fails to compile: pecl_http-3.1.0/src/php_http_etag.c:63:20: \#if with no expression
#BROKEN_mips64=	fails to compile: pecl_http-3.1.0/src/php_http_etag.c:63:20: \#if with no expression

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2@${PHP_FLAVOR} \
		re2c:devel/re2c
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libicudata.so:devel/icu
RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2@${PHP_FLAVOR}

USES=		php:pecl
USE_PHP=	hash:build iconv:build zlib:build
IGNORE_WITH_PHP=	74

.include <bsd.port.mk>
