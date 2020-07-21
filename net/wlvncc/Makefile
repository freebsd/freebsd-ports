# $FreeBSD$

PORTNAME=	wlvncc
PORTVERSION=	s20200719
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland Native VNC Client

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libaml.so:devel/aml \
		libwayland-client.so:graphics/wayland \
		libvncclient.so:net/libvncserver \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	any1
GH_TAGNAME=	f7aab11
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
