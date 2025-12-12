PORTNAME=	xlibre-ephyr
PORTVERSION=	${XLIBRE_VER}
CATEGORIES=	x11-servers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	Xlibre Xephyr server
WWW=		https://github.com/X11Libre/xserver/

LICENSE=	MIT

CONFLICTS_INSTALL=	xephyr

USES+=		xlibre-cat:server
USE_XORG+=xcb

MESON_ARGS+=	-Dglamor=true
LIB_DEPENDS+=	libepoxy.so:graphics/libepoxy

LIB_DEPENDS+=	libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-util.so:x11/xcb-util

.include "../xlibre-server/Makefile.common"
