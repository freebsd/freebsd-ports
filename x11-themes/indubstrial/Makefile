# New ports collection makefile for:	Indubstrial
# Date Created:				20 August 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	indubstrial
PORTVERSION=	0.3.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.gnome.org/~jdub/2004/indubstrial/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A clean, clear modification on the Industrial GTK+ and Metacity themes

RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.4.0/engines/libindustrial.so:${PORTSDIR}/x11-themes/gnome-themes-extras

WRKSRC=		${WRKDIR}/Indubstrial
NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomeprefix metacity

do-install:
	${MKDIR} ${PREFIX}/share/themes/Indubstrial/gtk-2.0
	${MKDIR} ${PREFIX}/share/themes/Indubstrial/gtk
	${MKDIR} ${PREFIX}/share/gnome/themes/Indubstrial/metacity-1
	${INSTALL_DATA} ${WRKSRC}/gtk-2.0/gtkrc \
		${PREFIX}/share/themes/Indubstrial/gtk-2.0
	${INSTALL_DATA} ${WRKSRC}/gtk/gtkrc \
		${PREFIX}/share/themes/Indubstrial/gtk
	${INSTALL_DATA} ${WRKSRC}/metacity-1/metacity-theme-1.xml \
		${PREFIX}/share/gnome/themes/Indubstrial/metacity-1
	${INSTALL_DATA} ${WRKSRC}/index.theme \
		${PREFIX}/share/themes/Indubstrial

.include <bsd.port.mk>
