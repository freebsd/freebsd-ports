PORTNAME=	libdecor
DISTVERSION=	0.2.1
PORTREVISION=	1
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
MESON_ARGS=	-Ddemo=false

OPTIONS_DEFINE=	DBUS GTK3
OPTIONS_DEFAULT=DBUS GTK3
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_ENABLED=	dbus

GTK3_USE=		GNOME=gtk30
GTK3_MESON_ENABLED=	gtk

.include <bsd.port.mk>
