# $FreeBSD$

PORTNAME=	wayvnc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2-146
DISTVERSIONSUFFIX=	-gf9b3d98
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VNC server for wlroots-based compositors

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libaml.so:devel/aml \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libneatvnc.so:net/neatvnc \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
USE_GL=		gbm
USE_LDCONFIG=	yes
GH_ACCOUNT=	any1
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
