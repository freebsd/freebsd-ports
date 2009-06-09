# Ports collection makefile for:  pecl-timezonedb
# Date created:			  20 Oct 2006
# Whom:				  Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timezonedb
DISTVERSION=	2009.8
CATEGORIES=	misc
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Timezone Database to be used with PHP's date and time functions

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	timezonedb
IGNORE_WITH_PHP=4

CONFIGURE_ARGS=	--enable-timezonedb

.include <bsd.port.mk>
