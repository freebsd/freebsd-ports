# Created by: Alan Garfield <alan@fromorbit.com>
# $FreeBSD$

PORTNAME=	ps
PORTVERSION=	1.3.6
PORTREVISION=	3
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	ps-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	alan@fromorbit.com
COMMENT=	PHP extension for pslib to generate postscript

DEPRECATED=	requires php53, security EOL reached 14 Aug 2014
EXPIRATION_DATE=	2015-04-15

LIB_DEPENDS=	libps.so:${PORTSDIR}/print/pslib

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}
IGNORE_WITH_PHP=5 55 56

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl|-lintl|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
