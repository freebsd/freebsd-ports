# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	gtk-murrina-lightblue
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	45384-MurrinaLightBlue

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrina LightBlue GTK+ 2.x cairo based theme

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine

USES=		gnome

GTKRC_DIR=	${DISTNAME}/gtk-2.0
USE_GNOME=	gtk20
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/MurrinaLightBlue/gtk-2.0
	@${INSTALL_DATA} ${WRKDIR}/MurrinaLightBlue/gtk-2.0/gtkrc ${STAGEDIR}${PREFIX}/share/themes/MurrinaLightBlue/gtk-2.0

.include <bsd.port.mk>
