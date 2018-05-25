# $FreeBSD$

PORTNAME=	libstorj
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jhixson@gmail.com
COMMENT=	C library and CLI for encrypted file transfer on the Storj network

LICENSE=	LGPL21+

BROKEN_aarch64=		fails to build: invokes x86 assembler
BROKEN_armv6=		fails to build: invokes x86 assembler
BROKEN_armv7=		fails to build: invokes x86 assembler
BROKEN_mips=		fails to build: invokes x86 assembler
BROKEN_mips64=		fails to build: invokes x86 assembler
BROKEN_powerpc64=	fails to compile: storj.c:135: 'for' loop initial declaration used outside C99 mode

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libuv.so:devel/libuv \
		libcurl.so:ftp/curl \
		libnettle.so:security/nettle \
		libmicrohttpd.so:www/libmicrohttpd

USES=		autoreconf gmake libtool localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Storj

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

#CFLAGS+=	-I. -I${LOCALBASE}/include
#LDFLAGS+=	-L. -L${LOCALBASE}/lib

.include <bsd.port.mk>
