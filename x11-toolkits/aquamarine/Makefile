PORTNAME=	aquamarine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
CATEGORIES=	x11-toolkits

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Very light linux rendering backend library
WWW=		https://github.com/hyprwm/aquamarine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		hyprwayland-scanner>=0.4.0:devel/hyprwayland-scanner \
		wayland-protocols>0:graphics/wayland-protocols \
		hwdata>0:misc/hwdata
LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libdisplay-info.so:sysutils/libdisplay-info \
		libseat.so:sysutils/seatd \
		libinput.so:x11/libinput
RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri

USES=		cmake:testing compiler:c++11-lib gl pathfix pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_GL=		egl gbm glesv2
USE_LDCONFIG=	yes
USE_XORG=	pixman

PLIST_SUB=	SOVERSION_MAJOR=8 \
		SOVERSION_FULL=${DISTVERSION:C/-.*//}

# XXX Drop after FreeBSD 13.5 EOL around 2026-04-30
# https://cgit.freebsd.org/src/commit/?id=af93fea71038
.if !exists(/usr/include/sys/timerfd.h)
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
.endif

.include <bsd.port.mk>
