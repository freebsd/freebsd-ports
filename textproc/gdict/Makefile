# New ports collection makefile for:	gdict
# Version required:		0.7
# Date created:			Sun Jul 18 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

DISTNAME=	gdict-0.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.psilord.com/code/gdict/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdict ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cdict ${PREFIX}/bin

.include <bsd.port.mk>
