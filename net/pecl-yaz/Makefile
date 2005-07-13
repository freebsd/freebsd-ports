# New ports collection makefile for:	pecl-yaz
# Date created:			9 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	1.0.3
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension that implements a Z39.50 client

LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-yaz=${LOCALBASE}

.include <bsd.port.mk>
