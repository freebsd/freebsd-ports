# New ports collection makefile for:	pecl-xdiff
# Date created:			19 April 2006
# Whom:				Larry Rosenman <ler@lerctr.org>
#
# $FreeBSD$
#

PORTNAME=	xdiff
PORTVERSION=	1.4
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ler@lerctr.org
COMMENT=	A PECL extension to create/apply binary and text patches

LIB_DEPENDS=	xdiff.0:${PORTSDIR}/textproc/libxdiff

USE_PHP=	yes
USE_PHPEXT=	yes

post-configure:
	echo "#define HAVE_XDL_ALLOCATOR_PRIV 1" >>${WRKSRC}/config.h
.include <bsd.port.mk>
