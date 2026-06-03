PORTNAME=	jellyfin-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Jellyfin Desktop Client
WWW=		https://github.com/jellyfin/jellyfin-desktop-qt

LICENSE=	GPLv2

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libMpvQt.so:multimedia/mpvqt \
		libcec.so:multimedia/libcec \
		libminizip.so:archivers/minizip

USES=		cmake gl iconv pkgconfig python:build qt:6 sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jellyfin
GH_PROJECT=	jellyfin-desktop-qt

USE_GL=		opengl
USE_SDL=	sdl2
USE_QT=		base declarative positioning webchannel webengine
USE_XORG=	ice sm x11 xext xrandr

.include <bsd.port.mk>
