PORTNAME=	libdecor
DISTVERSION=	0.2.4
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

CAIRO_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
CAIRO_USES=		gnome
CAIRO_USE=		GNOME=cairo,pango

# Unused by the main library
DBUS_LIB_DEPENDS=	${"${PORT_OPTIONS:NDBUS}":?libdbus-1.so\:devel/dbus:}
DBUS_MESON_ENABLED=	dbus

EXAMPLES_MESON_TRUE=	demo install_demo
EXAMPLES_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EXAMPLES_LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
EXAMPLES_USES=		gl
EXAMPLES_USE=		GL=egl,opengl

GTK3_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
GTK3_USES=		gnome
GTK3_USE=		GNOME=cairo,gtk30
GTK3_MESON_ENABLED=	gtk

post-patch-CAIRO-off:
	@${REINPLACE_CMD} '/cairo/d' ${WRKSRC}/src/plugins/meson.build
	@${REINPLACE_CMD} "s/'cairo'/&, required: false, disabler: true/" \
		${WRKSRC}/src/plugins/common/meson.build

.include <bsd.port.mk>
