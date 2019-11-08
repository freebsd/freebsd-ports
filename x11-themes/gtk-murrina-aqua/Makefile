# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	gtk-murrina-aqua
PORTVERSION=	0.1
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	LOCAL/itetcu \
		http://www5.frugalware.org/packages/frugalware/pub/frugalware/frugalware-stable/source/gnome-extra/gtk+2-engines-murrine/
DISTNAME=	Murrina-Aqua

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrina Aqua GTK+ 2.x cairo based theme

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.so:x11-themes/gtk-murrine-engine

USES=		gnome

GTKRC_DIR=	${DISTNAME}/gtk-2.0
USE_GNOME=	gtk20
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/themes/${GTKRC_DIR}
	@${INSTALL_DATA} ${WRKDIR}/${GTKRC_DIR}/gtkrc ${STAGEDIR}${LOCALBASE}/share/themes/${GTKRC_DIR}

.include <bsd.port.mk>
