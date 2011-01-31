# Ports collection makefile for:   pear-tidy
# Date created:                :   22 Mar 2006
# Whom:                        :   Rick van der Zwet (<rick@wzoeterwoude.net>)
#
# $FreeBSD$
#

PORTNAME=	tidy
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	rick@wzoeterwoude.net
COMMENT=	Tidy HTML Repairing and Parsing for PHP 4

BUILD_DEPENDS+=	${LOCALBASE}/include/tidy/tidy.h:${PORTSDIR}/www/tidy-devel

LICENSE=	PHP30

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	tidy
DEFAULT_PHP_VER?=	4
IGNORE_WITH_PHP=	5 52

CONFIGURE_ARGS=	--enable-tidy

.include <bsd.port.mk>
