# Ports collection makefile for:  pecl-pecl_http
# Date created:			  2005-12-19
# Whom:				  Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	pecl_http
DISTVERSION=	1.0.0RC3
CATEGORIES=	www pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	A PHP extension which provides extended HTTP request/response handling

USE_PHP=	session hash iconv
USE_PHPIZE=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	http

CONFIGURE_ARGS=	--enable-http

OPTIONS=	CURL			"Enable cURL HTTP requests"	on \
		MAGIC_MIME		"Enable response content type guessing"	off \
		ZLIB_COMPRESSION	"Enable support for encoded message bodies"	off

.include <bsd.port.pre.mk>

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

.if defined(WITH_ZLIB_COMPRESSION) && ${OSVERSION} < 500000
CONFIGURE_ARGS+=--with-http-zlib-compression=/usr
.else
CONFIGURE_ARGS+=--without-http-zlib-compression
.endif

.include <bsd.port.post.mk>
