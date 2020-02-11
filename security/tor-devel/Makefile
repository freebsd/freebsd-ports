# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	tor
DISTVERSION=	0.4.3.2
DISTVERSIONSUFFIX=	-alpha
CATEGORIES=	security net
MASTER_SITES=	TOR
PKGNAMESUFFIX=	-devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Anonymizing overlay network for TCP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe gmake pkgconfig # should be compiler:c99 or compiler:gnu99
USE_CSTD=	gnu99 # until this bug report is closed: https://trac.torproject.org/projects/tor/ticket/27900

CPE_VENDOR=	torproject
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}"
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

OPTIONS_DEFINE=	MANPAGES DOCS STATIC_TOR TCMALLOC
OPTIONS_GROUP=	COMPRESSION
OPTIONS_GROUP_COMPRESSION=ZSTD LZMA
OPTIONS_DEFAULT=MANPAGES ZSTD LZMA
OPTIONS_SUB=	yes
STATIC_TOR_DESC=	Build a static tor
TCMALLOC_DESC=		Use the tcmalloc memory allocation library
COMPRESSION_DESC=	Supported compression libraries

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message
SUB_LIST=	USER="${USERS}" GROUP="${GROUPS}"
PLIST_SUB=	USER="${USERS}" GROUP="${GROUPS}"

GROUPS=		_tor
USERS=		_tor

CONFLICTS_INSTALL=	tor

STATIC_TOR_USES=	ssl:build
STATIC_TOR_USES_OFF=	ssl

ZSTD_CONFIGURE_ENABLE=		zstd
ZSTD_CONFIGURE_ENV=TOR_ZSTD_LIBS="${TOR_ZSTD_LIBS}"
LZMA_CONFIGURE_ENABLE=		lzma

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	asciidoc:textproc/asciidoc
.else
CONFIGURE_ARGS+=	--disable-asciidoc
.endif

.if !defined(USE_GCC) && empty(CC:T:M*gcc4*) && \
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
BUILD_DEPENDS+=		${LOCALBASE}/lib/libtcmalloc.a:devel/google-perftools
.else
LIB_DEPENDS+=		libtcmalloc.so:devel/google-perftools
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s@(-z) (relro|now)@-Wl,\1,\2@g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|lib/tor|db/tor|' \
		${WRKSRC}/src/config/torrc.*.in \
		${WRKSRC}/doc/tor.1.* \
		${WRKSRC}/doc/tor.html.in

post-patch-STATIC_TOR-off:
	@${REINPLACE_CMD} -e "s@-ltcmalloc@${LOCALBASE}/lib/libtcmalloc.so@" \
		${WRKSRC}/configure

post-patch-STATIC_TOR-on:
	@${REINPLACE_CMD} -e "s@-ltcmalloc@${LOCALBASE}/lib/libtcmalloc.a@" \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}/var/log/tor ${STAGEDIR}/var/run/tor ${STAGEDIR}/var/db/tor

check regression-test test: build
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} check

.include <bsd.port.mk>
