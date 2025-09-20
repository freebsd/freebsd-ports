PORTNAME=	tor
DISTVERSION=	0.4.8.18
CATEGORIES=	security net
MASTER_SITES=	TOR

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Anonymizing overlay network for TCP
WWW=		https://www.torproject.org/

LICENSE=	BSD3CLAUSE

USES=		compiler:c11 cpe gmake pkgconfig

CPE_VENDOR=	torproject
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}"
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

OPTIONS_DEFINE=	DOCS MANPAGES POW STATIC_TOR TCMALLOC
OPTIONS_GROUP=	COMPRESSION TRACING
OPTIONS_GROUP_COMPRESSION=	ZSTD LZMA
OPTIONS_GROUP_TRACING=	LTTNG USDT LOG_DEBUG
OPTIONS_DEFAULT=	MANPAGES POW LZMA ZSTD
OPTIONS_SUB=	yes
STATIC_TOR_DESC=	Build a static tor
COMPRESSION_DESC=	Supported compression libraries
TRACING_DESC=		Tracing

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message
SUB_LIST=	USER="${USERS}" GROUP="${GROUPS}"
PLIST_SUB=	USER="${USERS}" GROUP="${GROUPS}"

GROUPS=		_tor
USERS=		_tor

CONFLICTS_INSTALL=	tor-devel

POW_DESC=		Enable PoW (Proof of Work) module (licence changes to GPL)
POW_CONFIGURE_ENABLE=	gpl # gpl enables POW

STATIC_TOR_USES=	ssl:build
STATIC_TOR_USES_OFF=	ssl

# compression options
ZSTD_CONFIGURE_ENABLE=		zstd
ZSTD_CONFIGURE_ENV=TOR_ZSTD_LIBS="${TOR_ZSTD_LIBS}"
LZMA_CONFIGURE_ENABLE=		lzma

# tracing options
LTTNG_DESC=			Build with LTTng-UST instrumentation
LTTNG_USES=			localbase
LTTNG_CONFIGURE_ENABLE=		tracing-instrumentation-lttng
LTTNG_LIB_DEPENDS=		liblttng-ust.so:sysutils/lttng-ust
USDT_DESC=			Build with tracing USDT instrumentation
USDT_CONFIGURE_ENABLE=		tracing-instrumentation-usdt
USDT_LIB_DEPENDS=		liblttng-ust.so:sysutils/lttng-ust
USDT_BROKEN=			error: use of undeclared identifier 'tor_circuit': https://gitlab.torproject.org/tpo/core/tor/-/issues/40174#note_2714275
LOG_DEBUG_DESC=			Build with tracing event to debug log
LOG_DEBUG_CONFIGURE_ENABLE=	tracing-instrumentation-log-debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	asciidoc:textproc/asciidoc
.else
CONFIGURE_ARGS+=	--disable-asciidoc
.endif

.if ${PORT_OPTIONS:MPOW}
LICENSE=	GPLv3
.else
LICENSE_FILE=	${WRKSRC}/LICENSE # BSD license file
.endif

.if !defined(USE_GCC) && \
empty(PORT_OPTIONS:MSTATIC_TOR)
CONFIGURE_ARGS+=	--enable-gcc-hardening
.else
CONFIGURE_ARGS+=	--disable-gcc-hardening
.endif

.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS +=	${LOCALBASE}/lib/libevent.a:devel/libevent
CONFIGURE_ARGS+=	--enable-static-tor \
			--with-zlib-dir=/usr/lib --disable-linker-hardening
TOR_LIBEVENT_LIBS=	${LOCALBASE}/lib/libevent.a
.  if ${PORT_OPTIONS:MZSTD}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libzstd.a:archivers/zstd
TOR_ZSTD_LIBS=		${LOCALBASE}/lib/libzstd.a
LDFLAGS+=		-lelf # needed by libexecinfo.a
.  endif
.else
CONFIGURE_ARGS+=	--enable-linker-hardening
LIB_DEPENDS+=		libevent.so:devel/libevent
TOR_LIBEVENT_LIBS=	-levent
.  if ${PORT_OPTIONS:MZSTD}
LIB_DEPENDS+=		libzstd.so:archivers/zstd
TOR_ZSTD_LIBS=		-lzstd
.  endif
.endif

.if ${PORT_OPTIONS:MTCMALLOC}
CONFIGURE_ARGS+=	--with-malloc=tcmalloc
.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libtcmalloc.a:devel/google-perftools # for static 'tor' executable
RUN_DEPENDS+=		google-perftool>0:devel/google-perftools # for a still-dynamic 'tor-gencert' executable
LDFLAGS+=		-lc++ -lm # required by libtcmalloc.a and isn't cocered by google-perftools' `pkg-config --libs libtcmalloc` output
.else
LIB_DEPENDS+=		libtcmalloc.so:devel/google-perftools
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s@(-z) (relro|now)@-Wl,\1,\2@g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|lib/tor|db/tor|' \
		${WRKSRC}/src/config/torrc.*.in \
		${WRKSRC}/doc/man/tor.1.* \
		${WRKSRC}/doc/man/tor.html.in

post-install:
	@${MKDIR} ${STAGEDIR}/var/log/tor ${STAGEDIR}/var/run/tor ${STAGEDIR}/var/db/tor

check regression-test test: build
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} check

.include <bsd.port.mk>
