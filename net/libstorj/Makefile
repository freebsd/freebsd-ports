# $FreeBSD$

PORTNAME=	libstorj
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	C library and CLI for encrypted file transfer on the Storj network

LICENSE=	LGPL21+

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libuv.so:devel/libuv \
		libcurl.so:ftp/curl \
		libnettle.so:security/nettle \
		libmicrohttpd.so:www/libmicrohttpd

USES=		autoreconf gmake libtool localbase pkgconfig
USE_CSTD=	gnu99

USE_GITHUB=	yes
GH_ACCOUNT=	Storj

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes  # ./storjtests.h:10:10: fatal error: 'mockbridgeinfo.json.h' file not found

#CFLAGS+=	-I. -I${LOCALBASE}/include
#LDFLAGS+=	-L. -L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
USE_GCC=	yes
.endif

.include <bsd.port.mk>
