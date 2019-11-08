# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	gtk-murrine-themes
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	http://cimi.netsons.org/media/download_gallery/
DISTNAME=	MurrineThemePack

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine theme pack

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine

GTKRC_DIR=	${DISTNAME}/gtk-2.0
USE_GNOME=	gtk20
NO_BUILD=	yes
USES=		gnome tar:bzip2

do-install:
	@(for theme in MurrinaCandy MurrinaCappuccino MurrinaEalm MurrinaNeoGraphite; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/$$theme/gtk-2.0; \
		${INSTALL_DATA} ${WRKDIR}/$$theme/gtk-2.0/gtkrc ${STAGEDIR}${PREFIX}/share/themes/$$theme/gtk-2.0; \
	done);

.include <bsd.port.mk>
