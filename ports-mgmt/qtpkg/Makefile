# New ports collection makefile for:	qtpkg
# Date created:				Wed Jan 3 2001
# Whom:					Trenton Schulz <twschulz@cord.edu>
#
# $FreeBSD$
#

PORTNAME=	qtpkg
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://gauss.cord.edu/homepages/twschulz/demo/
DISTNAME=	qtpkg

MAINTAINER=	twschulz@gloria.cord.edu

USE_QT_VER=	2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtpkg ${PREFIX}/sbin

.include <bsd.port.mk>
