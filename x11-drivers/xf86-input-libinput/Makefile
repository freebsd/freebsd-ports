PORTNAME=	xf86-input-libinput
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org libinput input driver
WWW=		https://www.x.org/

LICENSE=	MIT # various styles
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libinput.so:x11/libinput

USES=		pathfix tar:xz xorg-cat:driver

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
