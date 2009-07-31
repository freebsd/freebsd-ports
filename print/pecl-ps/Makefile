# Ports collection makefile for:  pear-ps
# Date created:		25 May 2007
# Whom:			Alan Garfield <alan@fromorbit.com>
#
# $FreeBSD$
#

PORTNAME=	ps
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	ps-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	alan@fromorbit.com
COMMENT=	PHP extension for pslib to generate postscript

LIB_DEPENDS=	ps.4:${PORTSDIR}/print/pslib

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=	5
PHP_MODNAME=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl|-lintl|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
