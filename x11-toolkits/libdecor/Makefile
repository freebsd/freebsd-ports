PORTNAME=	libdecor
DISTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Client-side decorations library for Wayland client
WWW=		https://gitlab.freedesktop.org/libdecor/libdecor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.15:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org

OPTIONS_DEFINE=	CAIRO DBUS EXAMPLES GTK3
OPTIONS_DEFAULT=CAIRO DBUS GTK3
OPTIONS_SUB=	yes

CAIRO_SUBPACKAGES=	cairo
CAIRO_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
#USES.cairo=		gnome
#USE_GNOME.cairo=	cairo pango
LIB_DEPENDS.cairo=	libgobject-2.0.so:devel/glib20 \
			libcairo.so:graphics/cairo \
			libpango-1.0.so:x11-toolkits/pango
SELF_DEPENDS.cairo=	main

# Unused by the main library
DBUS_LIB_DEPENDS.cairo=	libdbus-1.so:devel/dbus
DBUS_LIB_DEPENDS.examples=	libdbus-1.so:devel/dbus
DBUS_LIB_DEPENDS.gtk3=	libdbus-1.so:devel/dbus
DBUS_MESON_ENABLED=	dbus

EXAMPLES_SUBPACKAGES=	examples
EXAMPLES_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS.examples+=	libxkbcommon.so:x11/libxkbcommon
#USES.examples=		gl
#USE_GL.examples=	egl opengl
LIB_DEPENDS.examples+=	libEGL.so:graphics/libglvnd
SELF_DEPENDS.examples=	main
EXAMPLES_MESON_TRUE=	demo install_demo

GTK3_SUBPACKAGES=	gtk3
GTK3_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
#USES.gtk3=		gnome
#USE_GNOME.gtk3=		cairo gtk30
LIB_DEPENDS.gtk3+=	libglib-2.0.so:devel/glib20 \
			libcairo.so:graphics/cairo \
			libgtk-3.so:x11-toolkits/gtk30
SELF_DEPENDS.gtk3=	main
GTK3_MESON_ENABLED=	gtk

post-patch-CAIRO-off:
	@${REINPLACE_CMD} '/cairo/d' ${WRKSRC}/src/plugins/meson.build
	@${REINPLACE_CMD} "s/'cairo'/&, required: false, disabler: true/" \
		${WRKSRC}/src/plugins/common/meson.build

.include <bsd.port.mk>
