# $FreeBSD$

PORTNAME=	libudev-devd
PORTVERSION=	0.1
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	libudev-compatible interface for devd

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:devel/libevdev

USE_GITHUB=	yes
GH_ACCOUNT=	wulf7
GH_TAGNAME=	3fd2d11

USES=		autoreconf gmake libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
