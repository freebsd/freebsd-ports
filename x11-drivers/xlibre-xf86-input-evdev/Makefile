PORTNAME=	xlibre-xf86-input-evdev
PORTVERSION=	2.11.0.2
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre event device input driver
WWW=		https://github.com/X11Libre/xf86-input-evdev/

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xf86-input-evdev

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libmtdev.so:devel/libmtdev
RUN_DEPENDS=	webcamd>=3.1.0.1:multimedia/webcamd

USES=		pathfix xlibre-cat:driver
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	UDEV_CFLAGS=" " UDEV_LIBS=" "

.include <bsd.port.mk>
