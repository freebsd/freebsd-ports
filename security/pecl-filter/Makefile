# Ports collection makefile for:  pecl-filter
# Date created:			  2006-01-23
# Whom:				  Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	filter
DISTVERSION=	0.11.0
CATEGORIES=	security
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	PHP extension for safely dealing with input parameters

LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre

USE_PHP=	pcre
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	filter

DEFAULT_PHP_VER=	5
IGNORE_WITH_VER=	4

CONFIGURE_ARGS+=	--with-pcre-dir=${LOCALBASE}

.include <bsd.port.mk>
