# New ports collection makefile for:	wmWeather-1.28
# Date created:		26 January 1998
# Whom:			Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$

PORTNAME=	wmWeather
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	misc windowmaker
MASTER_SITES= 	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	kris@FreeBSD.org
COMMENT=	A WMaker dockapp which displays meteorological data for your city

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all

MAN1=		wmWeather.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmWeather ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/GrabWeather ${PREFIX}/bin/GrabWeather
	${INSTALL_MAN} ${WRKSRC}/wmWeather.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
