PORTNAME=	xlibre-xf86-input-synaptics
PORTVERSION=	25.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre synaptics input driver
WWW=		https://github.com/X11Libre/xf86-input-synaptics/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix xorg xlibre-cat:driver
USE_XORG=	x11 xtst

OPTIONS_DEFINE=	EVDEV
OPTIONS_DEFAULT=EVDEV
EVDEV_DESC=	Use evdev for input events (requires kernel support)

EVDEV_CONFIGURE_ENV=	BUILD_EVENTCOMM=yes
EVDEV_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev

.include <bsd.port.mk>
