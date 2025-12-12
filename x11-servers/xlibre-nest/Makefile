PORTNAME=	xlibre-nest
PORTVERSION=	${XLIBRE_VER}
CATEGORIES=	x11-servers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	Xlibre Xnest server
WWW=		https://github.com/X11Libre/xserver/

LICENSE=	MIT

CONFLICTS_INSTALL=	xorg-nestserver

USES=		xlibre-cat:server
USE_XORG+=xcb

LIB_DEPENDS+=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm

.include "../xlibre-server/Makefile.common"
