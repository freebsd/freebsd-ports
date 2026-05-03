PORTNAME=	xf86-input-libinput
PORTVERSION=	1.5.0
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org libinput input driver
WWW=		https://gitlab.freedesktop.org/xorg/driver/xf86-input-libinput/

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libinput.so:x11/libinput

USES=		pathfix tar:xz xorg-cat:driver

TEST_TARGET=	check

.include <bsd.port.mk>
