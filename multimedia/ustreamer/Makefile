# $FreeBSD$

PORTNAME=	ustreamer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10
CATEGORIES=	multimedia net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and fast MJPG-HTTP streamer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c11 gmake jpeg localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	pi-kvm

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ustreamer

.include <bsd.port.mk>
