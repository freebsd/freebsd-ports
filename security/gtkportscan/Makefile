# New ports collection makefile for:	gtkportscan
# Version required:	1.1
# Date created:		11 March 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	gtkportscan-1.1
CATEGORIES=	security net
MASTER_SITES=	http://www.calpoly.edu/~rbarrero/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/gtkscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkportscan ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/portscan ${PREFIX}/bin

.include <bsd.port.mk>
