# Ports collection makefile for:  pear-enchant
# Date created:			  17 April 2008
# Whom:				  Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	enchant
DISTVERSION=	1.0.2
CATEGORIES=	textproc devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	wenheping@gmail.com
COMMENT=	Libenchant Binder that Support Near All Spelling Tools

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}

.include <bsd.port.mk>
