# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-icon-theme-faenza
PORTVERSION=	1.8.0
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of Faenza and Faience icons for the MATE desktop

PORTSCOUT=	limitw:1,even

USES=		tar:xz
NO_BUILD=	yes
INSTALLS_ICONS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	(cd ${WRKSRC} && ${FIND} matefaenza -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${PREFIX}/share/icons)
	(cd ${WRKSRC} && ${FIND} matefaenzadark -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${PREFIX}/share/icons)
	(cd ${WRKSRC} && ${FIND} matefaenzagray -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>
