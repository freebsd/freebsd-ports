# New ports collection makefile for:	gtk-murrina-lightblue
# Date created:		2006-08-20
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-murrina-lightblue
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	45384-MurrinaLightBlue

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrina LightBlue GTK+ 2.x cairo based theme

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine

GTKRC_DIR=	${DISTNAME}/gtk-2.0
USE_GNOME=	gtk20
NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/themes/MurrinaLightBlue/gtk-2.0
	@${INSTALL_DATA} ${WRKDIR}/MurrinaLightBlue/gtk-2.0/gtkrc ${LOCALBASE}/share/themes/MurrinaLightBlue/gtk-2.0

.include <bsd.port.mk>
