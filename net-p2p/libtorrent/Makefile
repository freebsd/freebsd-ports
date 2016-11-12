# $FreeBSD$

PORTNAME=	libtorrent
PORTVERSION=	0.13.6
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://rtorrent.net/downloads/

MAINTAINER=	pipfstarrd@openmailbox.org
COMMENT=	BitTorrent Library written in C++

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	rblibtorrent-[0-9]* rblibtorrent-devel-[0-9]*

USES=		compiler:c++11-lang libtool pathfix pkgconfig ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" OPENSSL_CFLAGS="-I\
								${OPENSSLINC}"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IPV6 KQUEUE
OPTIONS_DEFAULT=KQUEUE
KQUEUE_DESC=	Use kqueue(2) support

# This makes sure that /usr/local/lib appears before /usr/lib when
# linking libtorrent to avoid linking with base's libcrypto.
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

IPV6_CONFIGURE_ENABLE=	ipv6
KQUEUE_CONFIGURE_WITH=	kqueue

.include <bsd.port.pre.mk>

# Disable amd64 atomic ops on i386 when using gcc
# undefined reference to __sync_add_and_fetch_8
# undefined reference to __sync_fetch_and_and_8
.if ${ARCH} == i386 && ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=--disable-instrumentation
.endif

# Workaround to build on >= 10.x
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
USE_CXXSTD=	c++11
EXTRA_PATCHES+=	${FILESDIR}/extra-clang
.endif

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
	@${FIND} ${WRKSRC} \( -name '*.h' -o -name '*.cc' \) -type f \
		-exec ${REINPLACE_CMD} -e 's/tr1::/std::/g' {} \; \
		-exec ${REINPLACE_CMD} -e 's/std::std::/std::/g' {} \; \
		-exec ${REINPLACE_CMD} -e '/namespace tr1/d' {} \; \
		-exec ${REINPLACE_CMD} -e '/include/s,tr1/,,' {} \;
	@${REINPLACE_CMD} -e 's/\.assign/.fill/' \
		${WRKSRC}/src/torrent/utils/extents.h \
		${WRKSRC}/src/torrent/utils/log.cc
.endif

.include <bsd.port.post.mk>
