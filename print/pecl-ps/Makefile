# Created by: Alan Garfield <alan@fromorbit.com>
# $FreeBSD$

PORTNAME=	ps
PORTVERSION=	1.3.6
PORTREVISION=	2
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
PHP_MODNAME=	${PORTNAME}
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-ldl|-lintl|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
