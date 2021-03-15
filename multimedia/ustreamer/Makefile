# $FreeBSD$

PORTNAME=	ustreamer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.20
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
GH_ACCOUNT=	pikvm

CFLAGS+=	-DWITH_PTHREAD_NP=0 # src/threading.h:101:4: error: thread_get_name() not implemented, you can disable it using WITH_PTHREAD_NP=0

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ustreamer \
		bin/ustreamer-dump \
		man1/ustreamer-dump.1.gz \
		man1/ustreamer.1.gz

BROKEN_FreeBSD_11=	error: thread_get_name() not implemented, you can disable it using WITH_PTHREAD_NP=0

.include <bsd.port.mk>
