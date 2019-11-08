# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-icon-theme-faenza
PORTVERSION=	1.20.0
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of Faenza and Faience icons for the MATE desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gnome tar:xz
NO_BUILD=	yes
INSTALLS_ICONS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	cd ${WRKSRC}; ${COPYTREE_SHARE} "matefaenza matefaenzadark" \
		${STAGEDIR}${PREFIX}/share/icons
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/matefaenzagray
	${INSTALL_DATA} ${WRKSRC}/matefaenzagray/index.theme \
		${STAGEDIR}${PREFIX}/share/icons/matefaenzagray/
	cd ${WRKSRC}/matefaenza; ${COPYTREE_SHARE} actions \
		${STAGEDIR}${PREFIX}/share/icons/matefaenzagray/

.include <bsd.port.mk>
