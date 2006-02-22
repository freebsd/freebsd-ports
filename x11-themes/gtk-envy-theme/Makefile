# New ports collection makefile for:	gtk-envy-theme
# Date Created:				2006 FEB 11
# Whom:					Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-envy-theme
PORTVERSION=	1.0.${SNAPSHOT}
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.gnome-look.org/content/files/
DISTNAME=	35093-Envy

MAINTAINER=	babak@farrokhi.net
COMMENT=	Envy theme for GTK+ 2.0

#RUN_DEPENDS=	${X11BASE}/share/icons/Tango:${PORTSDIR}/x11-themes/icons-tango

SNAPSHOT=	20060211
USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/Envy

do-install:
	${MKDIR} ${PREFIX}/share/themes/Envy/gtk-2.0
	${MKDIR} ${PREFIX}/share/gnome/themes/Envy/metacity-1
	@${CP} ${FILESDIR}/index.theme.in ${PREFIX}/share/themes/Envy/index.theme
	@${CP} -R ${WRKDIR}/Envy/gtk-2.0/* ${PREFIX}/share/themes/Envy/gtk-2.0
	@${CP} -R ${WRKDIR}/Envy/metacity-1/* ${PREFIX}/share/gnome/themes/Envy/metacity-1

.include <bsd.port.mk>
