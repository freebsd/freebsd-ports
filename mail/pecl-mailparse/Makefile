# Ports collection makefile for:  pear-mailparse
# Date created:			  09 January 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mailparse
PORTVERSION=	2.0b
PORTREVISION=	1
CATEGORIES=	mail www pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL extension to create and decode MIME messages

USE_PHP=	mbstring
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
WANT_PHP_PEAR=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	mailparse

.include <bsd.port.mk>
