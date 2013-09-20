# $FreeBSD$

PORTNAME=	kde4-wallpapers-freebsd
PORTVERSION=	1.0
CATEGORIES=	x11-themes kde
MASTER_SITES=	LOCAL/avilla
DISTNAME=	stripes-freebsd-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FreeBSD wallpapers designed by KDE artwork team

CONFLICTS_INSTALL=	kde-workspace-4.[6-9].*

USE_BZIP2=	yes
USE_KDE4=	kdehier kdeprefix

NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/apps/plasma-desktop/init
	${INSTALL_DATA} ${FILESDIR}/05-freebsdWallpaper.js \
		${PREFIX}/share/apps/plasma-desktop/init
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${PREFIX}/share/wallpapers

.include <bsd.port.mk>
