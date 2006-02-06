# Ports collection makefile for:  pecl-pecl_http
# Date created:			  2005-12-19
# Whom:				  Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	pecl_http
PORTVERSION=	0.22.0
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	A PHP extension which provides extended HTTP request/response handling

USE_PHP=	session zlib
USE_PHPIZE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	http

RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/hash.so:${PORTSDIR}/security/pecl-hash

CONFIGURE_ARGS=	--enable-http

OPTIONS=	CURL			"Enable cURL HTTP requests"	on \
		MAGIC_MIME		"Enable response content type guessing"	off \
		ZLIB_COMPRESSION	"Enable support for encoded message bodies"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on FreeBSD <= 4.x
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-http-curl-requests=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-http-curl-requests
.endif

.if defined(WITH_MAGIC_MIME)
LIB_DEPENDS+=	magic.1:${PORTSDIR}/sysutils/file
CONFIGURE_ARGS+=--with-http-magic-mime=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-http-magic-mime
.endif

.if defined(WITH_ZLIB_COMPRESSION)
CONFIGURE_ARGS+=--with-http-zlib-compression=/usr
.else
CONFIGURE_ARGS+=--without-http-zlib-compression
.endif

.include <bsd.port.post.mk>
