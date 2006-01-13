# Ports collection makefile for:  pecl-hash
# Date created:			  2005-12-07
# Whom:				  Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	hash
DISTVERSION=	1.1
CATEGORIES=	security www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	pHASH Message Digest Framework for PHP

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	hash

.include <bsd.port.pre.mk>

.if ${PHP_VER} == 4
IGNORE=		requires PHP version 5.0.3 or higher
.endif

.include <bsd.port.post.mk>
