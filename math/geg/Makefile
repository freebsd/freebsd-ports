# New ports collection makefile for:		geg
# Date created:					8 Aug 1998
# Whom:						rom
#
# $FreeBSD$
#

PORTNAME=	geg
PORTVERSION=	1.0.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.infolaunch.com/~daveb/
MASTER_SITE_SUBDIR=	science/visualization/plotting

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/geg ${PREFIX}/bin

.include <bsd.port.mk>
