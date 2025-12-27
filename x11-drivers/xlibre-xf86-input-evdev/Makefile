PORTNAME=	xlibre-xf86-input-evdev
PORTVERSION=	25.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre event device input driver
WWW=		https://github.com/X11Libre/xf86-input-evdev/

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libmtdev.so:devel/libmtdev
RUN_DEPENDS=	webcamd>=3.1.0.1:multimedia/webcamd

USES=		pathfix xlibre-cat:driver

CONFIGURE_ENV=	UDEV_CFLAGS=" " UDEV_LIBS=" "

.include <bsd.port.mk>
