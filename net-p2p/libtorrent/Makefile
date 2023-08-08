PORTNAME=	libtorrent
PORTVERSION=	0.13.8
CATEGORIES=	net-p2p
MASTER_SITES=	https://rtorrent.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent Library written in C++
WWW=		https://github.com/rakshasa/libtorrent

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang cpe libtool localbase:ldflags pathfix pkgconfig ssl
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" OPENSSL_CFLAGS="-I\
								${OPENSSLINC}"

OPTIONS_DEFINE=	KQUEUE
OPTIONS_DEFAULT=KQUEUE

KQUEUE_DESC=	Use kqueue(2) support

# This makes sure that /usr/local/lib appears before /usr/lib when
# linking libtorrent to avoid linking with base's libcrypto.
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

KQUEUE_CONFIGURE_WITH=	kqueue

.include <bsd.port.pre.mk>

# Disable instrumentation, which requires 64-bit atomic ops, on i386 when using
# gcc to avoid linking errors:
# /usr/local/lib/libtorrent.so: undefined reference to `__sync_add_and_fetch_8'
# /usr/local/lib/libtorrent.so: undefined reference to `__sync_fetch_and_and_8'
.if ${ARCH} == i386 && ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=--disable-instrumentation
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtorrent.so.21.0.0

.include <bsd.port.post.mk>
