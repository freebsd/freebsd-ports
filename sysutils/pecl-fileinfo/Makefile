# New ports collection makefile for:	pecl-fileinfo
# Date created:			21 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fileinfo
PORTVERSION=	1.0.4
CATEGORIES=	sysutils pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Fileinfo-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to retrieve info about files

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-fileinfo=/usr

.include <bsd.port.mk>
