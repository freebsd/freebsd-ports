# New ports collection makefile for:	wmWeather-1.1
# Version required:     1.1
# Date created:		26 January 1998
# Whom:			Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$

DISTNAME=       wmWeather-1.1
CATEGORIES=	misc windowmaker
MASTER_SITES=	ftp://leadbelly.lanl.gov/pub/mgh/

MAINTAINER=	kkennawa@physics.adelaide.edu.au

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/net/wget

WRKSRC=		${WRKDIR}/${DISTNAME}/wmWeather

USE_GMAKE=	yes
ALL_TARGET=	clean all

MAN1=		wmWeather.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmWeather ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/GrabWeather ${PREFIX}/bin/GrabWeather
	${INSTALL_MAN} ${WRKSRC}/wmWeather.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
