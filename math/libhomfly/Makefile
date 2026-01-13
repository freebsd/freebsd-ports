PORTNAME=	libhomfly
DISTVERSION=	1.03
CATEGORIES=	math
MASTER_SITES=	https://github.com/miguelmarco/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to compute the homfly polynomial of knots and link
WWW=		https://github.com/miguelmarco/libhomfly

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libgc-threaded.so:devel/boehm-gc-threaded

USES=		libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	check

PLIST_FILES=	include/homfly.h	\
		lib/libhomfly.a		\
		lib/libhomfly.so	\
		lib/libhomfly.so.0	\
		lib/libhomfly.so.0.0.0	\
		libdata/pkgconfig/libhomfly.pc

.include <bsd.port.mk>
