# New ports collection makefile for:	gtk-aqualightblue-theme
# Date Created:				14 March 2003
# Whom:					Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	gtk-aqualightblue-theme
PORTVERSION=	0.1
PORTREVISION=	9
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	aqualightblue-gtk2
DISTNAME=	aqualightblue-gtk2-default

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A port of the GTK+ AquaLightBlue theme to GTK+ 2.0

WRKSRC=		${WRKDIR}/AquaLightBlue

NO_BUILD=	yes
USE_GNOME=	gtk20

do-install:
	${MKDIR} ${PREFIX}/share/themes/AquaLightBlue/gtk-2.0
	${FIND} ${WRKSRC}/gtk -type f | ${XARGS} -J % ${INSTALL_DATA} \
		% ${PREFIX}/share/themes/AquaLightBlue/gtk-2.0

.include <bsd.port.mk>
