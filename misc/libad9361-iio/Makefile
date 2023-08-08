PORTNAME=	libad9361-iio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IIO AD9361 library for filter design, handling, multi-chip sync, etc
WWW=		https://analogdevicesinc.github.io/libad9361-iio/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libiio.so:misc/libiio

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	analogdevicesinc
USE_LDCONFIG=	yes

LDFLAGS+=	-lm

PLIST_FILES=	include/ad9361.h \
		lib/libad9361.so \
		lib/libad9361.so.0 \
		lib/libad9361.so.0.2 \
		libdata/pkgconfig/libad9361.pc

.include <bsd.port.mk>
