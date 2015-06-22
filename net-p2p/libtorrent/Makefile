# $FreeBSD$

PORTNAME=	libtorrent
PORTVERSION=	0.13.4
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent Library written in C++

CONFLICTS=	rblibtorrent-[0-9]* \
		rblibtorrent-devel-[0-9]*

USES=		compiler:c++11-lang libtool pathfix pkgconfig
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLBASE}/lib -ssl -crypto" OPENSSL_CFLAGS="-I${OPENSSLBASE}/include"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	KQUEUE IPV6
OPTIONS_DEFAULT=	KQUEUE
KQUEUE_DESC=	Use kqueue(2) support

.include <bsd.port.pre.mk>

# Disable amd64 atomic ops on i386 when using gcc
# undefined reference to __sync_add_and_fetch_8
# undefined reference to __sync_fetch_and_and_8
.if ${ARCH} == "i386" && ${COMPILER_TYPE} == "gcc"
CONFIGURE_ARGS+=	--disable-instrumentation
.endif

# Workaround to build on >= 10.x
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
CXXFLAGS+=	-std=c++11
EXTRA_PATCHES+=	${FILESDIR}/extra-clang
.endif

.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=	--with-kqueue
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure
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
