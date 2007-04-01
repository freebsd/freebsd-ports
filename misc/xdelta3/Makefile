# New ports collection makefile for:		xdelta
# Date created:    01 April 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	xdelta
PORTVERSION=	3.0q
CATEGORIES=	misc devel
MASTER_SITES=	http://xdelta.googlecode.com/files/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//g}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

ALL_TARGET=	xdelta3

PLIST_FILES=	bin/xdelta3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${PREFIX}/bin/

.include <bsd.port.mk>
