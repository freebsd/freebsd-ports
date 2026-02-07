PORTNAME=	jellyfin-media-player
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Jellyfin Desktop Client
WWW=		https://github.com/jellyfin/jellyfin-media-player

LICENSE=	GPLv2

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libcec.so:multimedia/libcec

USES=		cmake qt:5 sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jellyfin

USE_QT=		core gui network webengine webchannel dbus qmake buildtools \
		quickcontrols xml x11extras
USE_SDL=	sdl2
USE_XORG=	xext

.include <bsd.port.mk>
