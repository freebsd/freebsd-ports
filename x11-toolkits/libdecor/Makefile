PORTNAME=	libdecor
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	ca1dd07bbdbd.patch:-p1 # https://gitlab.gnome.org/jadahl/libdecor/-/merge_requests/74
PATCHFILES+=	4b8b2865e1e5.patch:-p1 # https://gitlab.gnome.org/jadahl/libdecor/-/merge_requests/75
PATCHFILES+=	51e9db022fe2.patch:-p1 # https://gitlab.gnome.org/jadahl/libdecor/-/merge_requests/75

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Client-side decorations library for Wayland client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo pango
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	jadahl
GL_COMMIT=	3ec3fadd59a21835079fbb3046d2bec6c649d6fa
MESON_ARGS=	-Ddemo=false

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_ENABLED=	dbus

.include <bsd.port.mk>
