# New ports collection makefile for:	spruce
# Version required:   	0.4.5
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	spruce-0.4.5
CATEGORIES=	mail
MASTER_SITES=	http://www.xtorshun.org/spruce/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spruce ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/spruce
	${INSTALL_DATA} ${WRKSRC}/xpm/* ${PREFIX}/share/spruce

.include <bsd.port.mk>
