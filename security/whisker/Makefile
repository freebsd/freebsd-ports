# New ports collection makefile for:	whisker
# Date created:		7 Jan 2000
# Whom:			kris@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	whisker
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.wiretrip.net/rfp/bins/whisker/
DISTNAME=	${PORTNAME}

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/v${PORTVERSION}
NO_BUILD=	yes

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/whisker.pl ${PREFIX}/bin/whisker
		${MKDIR} ${PREFIX}/share/whisker
		${INSTALL_DATA} ${WRKSRC}/*.db ${PREFIX}/share/whisker
		${MKDIR} ${PREFIX}/share/doc/whisker
		${INSTALL_DATA} ${WRKSRC}/whisker.txt ${PREFIX}/share/doc/whisker

.include <bsd.port.mk>
