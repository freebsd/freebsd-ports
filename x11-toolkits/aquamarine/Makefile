PORTNAME=	aquamarine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
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
USE_GL=		egl gbm glesv2
USE_XORG=	pixman
GH_ACCOUNT=	hyprwm
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

.include <bsd.port.mk>
