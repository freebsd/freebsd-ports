# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.4.0
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libepoll-shim.so:wayland/libepoll-shim \
		libwacom.so:wayland/libwacom \
		libudev.so:wayland/libudev-devd \
		libmtdev.so:devel/libmtdev

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_TAGNAME=	67c9796

USES=		autoreconf gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
