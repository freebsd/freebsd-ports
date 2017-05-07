# Created by: yohanesu75@gmail.com
# $FreeBSD$

PORTNAME=	weston
PORTVERSION=	1.11.0
CATEGORIES=	wayland
MASTER_SITES=	http://wayland.freedesktop.org/releases/
MAINTAINER=	x11@freebsd.org
COMMENT=	Wayland Reference Compositor

LICENSE=	MIT

USES=		autoreconf alias execinfo gmake pathfix jpeg libtool pkgconfig tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XORG=	x11 xcb xcursor
USE_GL=		egl gbm glesv2

#BROKEN=	Can build all clients but compositor does not work.
#TODO: Start a new port based on original code, not Dragonfly port.

#OPTIONS_DEFINE=	CLIENTS
# OPTIONS_SINGLE=	CAIRO
#OPTIONS_SINGLE_CAIRO=	CAIROIMAGE CAIROGL CAIROGLESV2
#CAIRO_DESC=	Cairo renderer
#CAIROIMAGE_DESC	= Image
#CAIROGL_DESC	= GL (enabled in cairo by default)
#CAIROGLESV2_DESC	= GLESv2 (requires cairo built with --enable-glesv2)
#CLIENTS_DESC = Build Weston clients
#OPTIONS_DEFAULT=CAIROIMAGE CLIENTS

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SUID
SUID_DESC=	Install weston-launch binary with setuid bit set
OPTIONS_DEFAULT=SUID


LIB_DEPENDS= \
		libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon		\
		libpixman-1.so:${PORTSDIR}/x11/pixman				\
		libcairo.so:${PORTSDIR}/graphics/cairo				\
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango		\
		libcolord.so:${PORTSDIR}/graphics/colord			\
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig	\
		libfreetype.so:${PORTSDIR}/print/freetype2			\
		libwayland-server.so:${PORTSDIR}/wayland/wayland	\
		libwayland-client.so:${PORTSDIR}/wayland/wayland	\
		libwayland-cursor.so:${PORTSDIR}/wayland/wayland	\
		libwayland-egl.so:${PORTSDIR}/graphics/libEGL		\
		libEGL.so:${PORTSDIR}/graphics/libEGL				\
		libGLESv2.so:${PORTSDIR}/graphics/libGL				\
		libevent.so:${PORTSDIR}/devel/libevent2				\
		libdrm.so:${PORTSDIR}/graphics/libdrm				\
		libpng.so:${PORTSDIR}/graphics/png					\
		libwebp.so:${PORTSDIR}/graphics/webp				\
		libffi.so:${PORTSDIR}/devel/libffi					\
		libepoll-shim.so:${PORTSDIR}/wayland/libepoll-shim	\
		libudev.so:${PORTSDIR}/wayland/libudev-devd			\
		libunwind.so:${PORTSDIR}/devel/libunwind			\
		libevdev.so:${PORTSDIR}/devel/libevdev				\
		libkbdev.so:${PORTSDIR}/wayland/libkbdev			\
		libinput.so:${PORTSDIR}/wayland/libinput			\
		libmtdev.so:${PORTSDIR}/devel/libmtdev

BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/wayland/wayland-protocols
BUILD_DEPENDS+=	wayland-scanner:${PORTSDIR}/wayland/wayland

RUN_DEPENDS=	${LOCALBASE}/lib/libglapi.so.0:${PORTSDIR}/graphics/libglapi

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-wayland-compositor
CONFIGURE_ARGS+=	--enable-x11-compositor
CONFIGURE_ARGS+=	--enable-drm-compositor
CONFIGURE_ARGS+=	--enable-rpi-compositor
CONFIGURE_ARGS+=	--enable-weston-launch
CONFIGURE_ARGS+=	--enable-xwayland
CONFIGURE_ARGS+=	--enable-clients
CONFIGURE_ARGS+=	--enable-demo-clients-install

CONFIGURE_ARGS+=	--disable-fbdev-compositor
CONFIGURE_ARGS+=	--disable-vaapi-recorder
CONFIGURE_ARGS+=	--disable-xwayland-test

CONFIGURE_ARGS+=	--with-cairo=image

# We handle setuid in the plist. This allows to build as a user.
CONFIGURE_ARGS+=	--disable-setuid-install

CONFIGURE_ENV+= LIBS="-lepoll-shim -lrt -lkbdev -lEGL"

# TODO: Fix include paths and libraries

# CONFIGURE_ENV+=	PKG_CONFIG_PATH="${PREFIX}/libdata/pkgconfig"
# CONFIGURE_ENV+= XWAYLAND_CLIENT_LIBS="-lepoll-shim -lrt"
# CONFIGURE_ENV+= EGL_CLIENT_LIBS="-lepoll-shim -lrt"

CONFIGURE_ENV+= EGL_TESTS_LIBS="-lwayland-client -lGLESv2 -lwayland-egl -lwayland-client"
CONFIGURE_ENV+= EGL_TESTS_CFLAGS="-L${STAGEDIR}${PREFIX}/lib -I${STAGEDIR}${PREFIX}/include"

#CLIENTS_CONFIGURE_ENABLE=	clients

#.include <bsd.port.options.mk>
# .if ${PORT_OPTIONS:MCAIROIMAGE}
# CONFIGURE_ARGS+=	--with-cairo=image
# .endif
# .if ${PORT_OPTIONS:MCAIROGL}
# CONFIGURE_ARGS+=	--with-cairo=gl
# .endif
# .if ${PORT_OPTIONS:MCAIROGLESV2}
# CONFIGURE_ARGS+=	--with-cairo=glesv2 --with-cairo-glesv2
# .endif

# post-patch:
# 	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|g' \
# 		${WRKSRC}/Makefile.am

PATHFIX_MAKEFILEIN?=	Makefile.am

.include <bsd.port.mk>
