PORTNAME=	hyprtoolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	x11-toolkits

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Modern C++ Wayland-native GUI toolkit
WWW=		https://github.com/hyprwm/hyprtoolkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	googletest>0:devel/googletest \
		hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libiniparser.so:devel/iniparser \
		libinotify.so:devel/libinotify \
		libhyprgraphics.so:graphics/hyprgraphics \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libaquamarine.so:x11-toolkits/aquamarine

USES=		cmake:testing compiler:c++20-lang gl gnome pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_GL=		egl gbm opengl
USE_GNOME=	cairo pango
USE_XORG=	pixman

LDFLAGS+=	-pthread

PLIST_SUB=	SOVERSION_FULL=${DISTVERSION} \
		SOVERSION_MAJOR=4

# XXX Drop after FreeBSD 13.5 EOL around 2026-04-30
# https://cgit.freebsd.org/src/commit/?id=af93fea71038
.if !exists(/usr/include/sys/timerfd.h)
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
.endif

.include <bsd.port.mk>
