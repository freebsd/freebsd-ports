# Created by: Philip Paeps <philip@paeps.cx>
# $FreeBSD$

PORTNAME=	gtk-aqualightblue-theme
PORTVERSION=	0.1
PORTREVISION=	11
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	aqualightblue-gtk2
DISTNAME=	aqualightblue-gtk2-default

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A port of the GTK+ AquaLightBlue theme to GTK+ 2.0

WRKSRC=		${WRKDIR}/AquaLightBlue

NO_BUILD=	yes
USE_GNOME=	gtk20

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/themes/AquaLightBlue/gtk-2.0
	${FIND} ${WRKSRC}/gtk -type f | ${XARGS} -J % ${INSTALL_DATA} \
		% ${PREFIX}/share/themes/AquaLightBlue/gtk-2.0

.include <bsd.port.mk>
