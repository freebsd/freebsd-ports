# New ports collection makefile for:	gtkportscan
# Version required:	1.2
# Date created:		11 March 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gtkportscan-1.2
CATEGORIES=	security net
#MASTER_SITES=	http://armageddon.splorg.org/gtkportscan/
MASTER_SITES=	http://www.FreeBSD.org/~cpiazza/distfiles/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/gtkportscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkportscan ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/portscan ${PREFIX}/bin

.include <bsd.port.mk>
