# New ports collection makefile for:	whisker
# Date created:		7 Jan 2000
# Whom:			kris@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	whisker
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.wiretrip.net/rfp/bins/whisker/
DISTNAME=	${PORTNAME}

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/v1.3

do-build:
		(cd ${WRKSRC}; ${SED} "s%y0y0y0%${PREFIX}%g" whisker.pl > whisker)

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/whisker ${PREFIX}/bin
		${MKDIR} ${PREFIX}/lib/whisker
		${INSTALL_DATA} ${WRKSRC}/*.db ${PREFIX}/lib/whisker
		${MKDIR} ${PREFIX}/share/doc/whisker
		${INSTALL_DATA} ${WRKSRC}/whisker.txt ${PREFIX}/share/doc/whisker

.include <bsd.port.mk>
