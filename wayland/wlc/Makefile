# $FreeBSD$

PORTNAME=	wlc
PORTVERSION=	0.0.5
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland compositor library

BUILD_DEPENDS=	wayland-protocols>=0:wayland/wayland-protocols \
		wayland-scanner:wayland/wayland
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libwayland-server.so:wayland/wayland \
		libdrm.so:graphics/libdrm \
		libudev.so:wayland/libudev-devd \
		libinput.so:wayland/libinput \
		libxcb-image.so:x11/xcb-util-image

RUN_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config

USE_GITHUB=	yes
GH_ACCOUNT=	cloudef
GH_TAGNAME=	fa780ce
GH_TUPLE=	cloudef:chck:3f27d2a:chck

USES=		cmake gnome localbase pkgconfig pathfix
USE_XORG=	pixman x11 xcb xcursor xfixes
USE_GL=		egl gbm glesv2
USE_GNOME=	cairo

¥¥CFLAGS+=	-fcolor-diagnostics

post-extract:
	@${RM} -r ${WRKSRC}/lib/chck
	@${LN} -s ${WRKSRC_chck} ${WRKSRC}/lib/chck

.include <bsd.port.mk>
