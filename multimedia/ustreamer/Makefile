PORTNAME=	ustreamer
DISTVERSIONPREFIX=	v
DISTVERSION=	5.46
CATEGORIES=	multimedia net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and fast MJPG-HTTP streamer
WWW=		https://github.com/pikvm/ustreamer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c11 gmake jpeg localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	pikvm

MAKE_ARGS=	WITH_PTHREAD_NP=0 MANPREFIX=${PREFIX}/share/man

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ustreamer \
		bin/ustreamer-dump \
		share/man/man1/ustreamer-dump.1.gz \
		share/man/man1/ustreamer.1.gz

.include <bsd.port.mk>
