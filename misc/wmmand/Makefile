# New ports collection makefile for:	wmMand
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmmand
PORTVERSION=	1.0
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
DISTNAME=	wmMand-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DockApp mandelbrot explorer

PLIST_FILES=	bin/wmMand
WRKSRC=		${WRKDIR}/${DISTNAME}/wmMand

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all

MAN1=		wmMand.1

.include <bsd.port.mk>
