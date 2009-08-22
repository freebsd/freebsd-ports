# Ports collection makefile for:  pear-enchant
# Date created:			  17 April 2008
# Whom:				  Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	enchant
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	textproc devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Libenchant Binder that Support Near All Spelling Tools

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

CONFIGURE_ARGS+=--with-enchant=${LOCALBASE}

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}

.include <bsd.port.mk>
