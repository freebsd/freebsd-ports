# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaim
PORTVERSION=	0.9.19
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.marko.net/pub/gaim/ \
		http://download.sourceforge.net/gaim/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--disable-esd

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gaim ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/gaim/pixmaps && ${CHMOD} a+rx ${PREFIX}/share/gaim/pixmaps
	@${ECHO} "===>   Installing pixmaps"
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/gaim/pixmaps

.include <bsd.port.mk>
