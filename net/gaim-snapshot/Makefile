# New ports collection makefile for:	gaim
# Version required:		0.1
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	gaim-19990311
PKGNAME=	gaim-0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/ \
		ftp://ftp.netmug.org/pub/FreeBSD/distfiles/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

ALL_TARGET=	gaim
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-patch:
	${CP} ${FILESDIR}/logo.xpm ${WRKSRC}/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gaim ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/gaim/pixmaps && chmod a+rx ${PREFIX}/share/gaim/pixmaps
	@ ${ECHO} "===>   Installing pixmaps"
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/gaim/pixmaps

.include <bsd.port.mk>
