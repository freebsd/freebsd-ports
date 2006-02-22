# New ports collection makefile for:	gtk-gray-theme
# Date Created:				2006 FEB 11
# Whom:					Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-gray-theme
PORTVERSION=	1.7
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.gnome-look.org/content/files/
DISTNAME=	34132-Gray

MAINTAINER=	babak@farrokhi.net
COMMENT=	Gray theme for GTK+ 2.0

RUN_DEPENDS=	${X11BASE}/share/icons/Tango:${PORTSDIR}/x11-themes/icons-tango

USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_GNOME=	gtk20

do-install:
	${MKDIR} ${PREFIX}/share/themes/Gray/gtk-2.0
	${MKDIR} ${PREFIX}/share/themes/Gray-Flat/gtk-2.0
	${MKDIR} ${PREFIX}/share/gnome/themes/Gray/metacity-1
	${MKDIR} ${PREFIX}/share/gnome/themes/Gray-Flat/metacity-1
	@${CP} ${WRKDIR}/Gray/index.theme ${PREFIX}/share/themes/Gray
	@${CP} -R ${WRKDIR}/Gray/gtk-2.0/* ${PREFIX}/share/themes/Gray/gtk-2.0
	@${CP} ${WRKDIR}/Gray-Flat/index.theme ${PREFIX}/share/themes/Gray-Flat
	@${CP} -R ${WRKDIR}/Gray-Flat/gtk-2.0/* ${PREFIX}/share/themes/Gray-Flat/gtk-2.0
	@${CP} -R ${WRKDIR}/Gray/metacity-1/* ${PREFIX}/share/gnome/themes/Gray/metacity-1
	@${CP} -R ${WRKDIR}/Gray-Flat/metacity-1/* ${PREFIX}/share/gnome/themes/Gray-Flat/metacity-1

.include <bsd.port.mk>
