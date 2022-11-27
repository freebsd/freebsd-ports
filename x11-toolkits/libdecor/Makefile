PORTNAME=	libdecor
DISTVERSION=	0.1.1
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Client-side decorations library for Wayland client
WWW=		https://gitlab.freedesktop.org/libdecor/libdecor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo pango
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	4db201134ab51950a1c673d77d7c4f2f7c7b48fd
MESON_ARGS=	-Ddemo=false

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_ENABLED=	dbus

.include <bsd.port.mk>
