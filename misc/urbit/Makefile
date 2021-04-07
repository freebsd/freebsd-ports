PORTNAME=	urbit
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.6.0
CATEGORIES=	misc emulators lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Peer-to-peer network of personal servers (a.k.a. "operating function")

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	__int128 is not supported on this target
NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	meson.build:273:2: ERROR: Problem encountered: Little endian encoding required

BUILD_DEPENDS=	re2c:devel/re2c
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgmp.so:math/gmp \
		libh2o.so:www/h2o \
		libsigsegv.so:devel/libsigsegv \
		libuv.so:devel/libuv

USES=		localbase:ldflags meson ncurses pkgconfig ssl
USE_GITHUB=	yes
GH_TUPLE=	urbit:commonmark-legacy:8555ef1:cmark/subprojects/commonmark-legacy # need the legacy version
GH_TUPLE+=	urbit:ed25519:ba4777a:ed25519/subprojects/ed25519 # not ported
GH_TUPLE+=	urbit:libscrypt:4ebe362:libscrypt/subprojects/libscrypt # https://github.com/urbit/urbit/issues/991
GH_TUPLE+=	urbit:murmur3:001378c:murmur3/subprojects/murmur3
GH_TUPLE+=	urbit:berkeley-softfloat-3:9d43420:softfloat/subprojects/softfloat3 # not ported

PLIST_FILES=	bin/urbit

post-install: # https://github.com/urbit/urbit/issues/992
	@${RM} -r ${STAGEDIR}${PREFIX}/include/*
	@${RM} ${STAGEDIR}${PREFIX}/lib/*.a

.include <bsd.port.mk>
