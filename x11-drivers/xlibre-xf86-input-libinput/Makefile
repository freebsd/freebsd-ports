PORTNAME=	xlibre-xf86-input-libinput
PORTVERSION=	1.5.1.0
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre libinput input driver
WWW=		https://github.com/X11Libre/xf86-input-libinput/

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xf86-input-libinput

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libinput.so:x11/libinput

USES=		pathfix tar:xz xlibre-cat:driver

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
