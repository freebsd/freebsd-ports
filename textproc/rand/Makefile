# New ports collection makefile for:	rand
# Version required:		1.5
# Date created:			Mon Jul 26 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

DISTNAME=	rand-1.5
CATEGORIES=	textproc
MASTER_SITES=	http://math.smsu.edu/~br0ke/files/

MAINTAINER=	domi@saargate.de

WRKSRC=		${WRKDIR}/rand

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rand ${PREFIX}/bin

.include <bsd.port.mk>
