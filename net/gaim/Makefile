# New ports collection makefile for:	gaim
# Version required:		0.9.6
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@blues.ghis.net>
#
# $Id: Makefile,v 1.5 1999/05/29 03:55:14 steve Exp $
#

DISTNAME=	gaim-0.9.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	jim@blues.ghis.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.2:${PORTSDIR}/devel/glib12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gaim ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/gaim/pixmaps && chmod a+rx ${PREFIX}/share/gaim/pixmaps
	@${ECHO} "===>   Installing pixmaps"
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/gaim/pixmaps

.include <bsd.port.mk>
