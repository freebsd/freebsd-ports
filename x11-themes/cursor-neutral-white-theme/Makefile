# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cursor-neutral-white-theme
DISTVERSION=	1.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	108143-Neutral++_White-${DISTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	White cursor theme based on neutral

USES=	tar:bzip2
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Neutral++_White

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/icons/Neutral++_White/cursors
	cd ${WRKSRC}/cursors && ${INSTALL_DATA} * \
		${STAGEDIR}${PREFIX}/lib/X11/icons/Neutral++_White/cursors

.include <bsd.port.mk>
