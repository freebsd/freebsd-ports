# Ports collection makefile for:  pecl-mogilegs
# Date created:			  Feb 20, 2011
# Whom:				  Wen Heping<wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mogilefs
PORTVERSION=	0.8.1
CATEGORIES=	sysutils pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PHP client library to communicate with the MogileFS storage

LIB_DEPENDS=	neon.27:${PORTSDIR}/www/neon29

LICENSE=	BSD

IGNORE_WITH_PHP=4

USE_PHP=	yes
USE_PHP_BUILD=	spl
USE_PHPIZE=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
