# New ports collection makefile for:		geg
# Version required:				1.0.1
# Date created:					8 Aug 1998
# Whom:						rom
#
# $FreeBSD$
#

DISTNAME=	geg-1.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.infolaunch.com/~daveb/ \
		ftp://metalab.unc.edu/pub/Linux/science/visualization/plotting/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/geg ${PREFIX}/bin

.include <bsd.port.mk>
