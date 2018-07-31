# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cursor-neutral-white-theme
DISTVERSION=	1.1.1
CATEGORIES=	x11-themes
MASTER_SITES=	https://dl.opendesktop.org/api/files/downloadfile/id/1460734982/s/8e93672a1ff38232a04132dbec6c80c6/t/1533029121/u/
DISTNAME=	108143-Neutral++_White-${DISTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	White cursor theme based on neutral

USES=		tar:xz
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Neutral++_White

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/Neutral++_White/cursors
	cd ${WRKSRC}/cursors && ${INSTALL_DATA} * \
		${STAGEDIR}${PREFIX}/share/icons/Neutral++_White/cursors

.include <bsd.port.mk>
