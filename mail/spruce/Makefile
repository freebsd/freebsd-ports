# New ports collection makefile for:	spruce
# Version required:   	0.4.7b
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.2 1999/06/19 08:25:16 cpiazza Exp $
#

DISTNAME=	spruce-0.4.7b
CATEGORIES=	mail
MASTER_SITES=	http://www.xtorshun.org/spruce/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spruce ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/spruce
	${INSTALL_DATA} ${WRKSRC}/xpm/* ${PREFIX}/share/spruce

.include <bsd.port.mk>
