# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-icon-theme-faenza
PORTVERSION=	1.6.0
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of Faenza and Faience icons for the MATE desktop

PORTSCOUT=	limitw:1,even

USE_XZ=		yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

pre-install:
# work around space in filename which make stage scripts barf
.	for i in 16 22 24 32 48
		${MV} ${WRKSRC}/matefaenza/apps/${i}/numpty\ physics.png \
			${WRKSRC}/matefaenza/apps/${i}/numptyphysics.png
.	endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	cd ${WRKSRC} && ${COPYTREE_SHARE} matefaenza ${STAGEDIR}${PREFIX}/share/icons
	cd ${WRKSRC} && ${COPYTREE_SHARE} matefaenzadark ${STAGEDIR}${PREFIX}/share/icons
	cd ${WRKSRC} && ${COPYTREE_SHARE} matefaenzagray ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
