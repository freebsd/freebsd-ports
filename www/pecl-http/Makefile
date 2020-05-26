# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	http
PORTVERSION=	3.2.3
CATEGORIES=	www
DISTNAME=	pecl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extended HTTP Support

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to compile: pecl_http-3.1.0/src/php_http_etag.c:63:20: \#if with no expression
BROKEN_mips64=		fails to compile: pecl_http-3.1.0/src/php_http_etag.c:63:20: \#if with no expression

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2@${PHP_FLAVOR} \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/propro.so:devel/pecl-propro2@${PHP_FLAVOR} \
		re2c:devel/re2c
RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2@${PHP_FLAVOR} \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/propro.so:devel/pecl-propro2@${PHP_FLAVOR}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent

USES=		php:pecl
USE_PHP=	zlib:build

CONFLICTS=	pecl-http[12]*

.include <bsd.port.mk>
