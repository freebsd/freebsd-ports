PORTNAME=	xlibre-xf86-input-libinput
PORTVERSION=	25.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre libinput input driver
WWW=		https://github.com/X11Libre/xf86-input-libinput/

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix tar:xz xlibre-cat:driver

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libinput.so:x11/libinput

.include <bsd.port.mk>
