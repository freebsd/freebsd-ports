# New ports collection makefile for:	wmWeather-1.28
# Version required:     1.28
# Date created:		26 January 1998
# Whom:			Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id: Makefile,v 1.2 1999/03/12 11:01:18 kris Exp $

DISTNAME=       wmWeather-1.28
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.physics.adelaide.edu.au/~kkennawa/

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/wmWeather

USE_GMAKE=	yes
ALL_TARGET=	clean all

MAN1=		wmWeather.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmWeather ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/GrabWeather ${PREFIX}/bin/GrabWeather
	${INSTALL_MAN} ${WRKSRC}/wmWeather.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
