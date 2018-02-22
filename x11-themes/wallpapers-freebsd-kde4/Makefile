# $FreeBSD$

PORTNAME=	wallpapers-freebsd-kde4
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-themes kde
MASTER_SITES=	LOCAL/avilla
DISTNAME=	stripes-freebsd-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FreeBSD wallpapers designed by KDE artwork team

USES=		tar:bzip2

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/apps/plasma-desktop/init
	${MKDIR} ${STAGEDIR}${PREFIX}/share/wallpapers
	${INSTALL_DATA} ${FILESDIR}/05-freebsdWallpaper.js \
		${STAGEDIR}${PREFIX}/share/apps/plasma-desktop/init
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/wallpapers

.include <bsd.port.mk>
