# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	worker
PORTVERSION=	3.8.3
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/

MAINTAINER=	mp39590@gmail.com
COMMENT=	X11 file manager based on Directory Opus of AmigaOS

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lib pkgconfig shebangfix tar:bzip2
GNU_CONFIGURE=	yes
USE_XORG=	x11 xinerama

SHEBANG_FILES=	${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/xeditor

OPTIONS_DEFINE=	AVFS HAL INOTIFY LUA XFT
OPTIONS_DEFAULT=	AVFS INOTIFY

OPTIONS_EXCLUDE_DragonFly=	AVFS

INOTIFY_DESC=	Monitor directory changes via libinotify
AVFS_DESC=	Use AVFS library to access an archives

AVFS_LIB_DEPENDS=	libavfs.so:sysutils/avfs

HAL_LIB_DEPENDS=	libhal-storage.so:sysutils/hal \
			libdbus-glib-1.so:devel/dbus-glib
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_LDFLAGS=	-L${LOCALBASE}/lib

LUA_CONFIGURE_OFF=	--disable-lua
LUA_USES=	lua:51

XFT_CONFIGURE_OFF=	--disable-xft
XFT_USE=	XORG=xft

.include <bsd.port.mk>
