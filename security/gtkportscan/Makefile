# New ports collection makefile for:	gtkportscan
# Version required:	1.1
# Date created:		11 March 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.2 1999/05/29 03:55:46 steve Exp $
#

DISTNAME=	gtkportscan-1.1
CATEGORIES=	security net
MASTER_SITES=	http://www.calpoly.edu/~rbarrero/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/gtkscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkportscan ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/portscan ${PREFIX}/bin

.include <bsd.port.mk>
