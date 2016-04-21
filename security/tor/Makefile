# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	tor
PORTVERSION=	0.2.7.6
PORTREVISION=	1
CATEGORIES=	security net ipv6
MASTER_SITES=	TOR

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Anonymizing overlay network for TCP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

USES=		cpe gmake
CPE_VENDOR=	torproject
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}" --disable-asciidoc
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

OPTIONS_DEFINE=	BUFFEREVENTS INSTR_DOWNLOADS \
		STATIC_TOR TCMALLOC TOR2WEB TRANSPARENT

BUFFEREVENTS_DESC=	Use libevent's buffered IO
INSTR_DOWNLOADS_DESC=	Instrument downloads for analysis
STATIC_TOR_DESC=	Build a static tor
TCMALLOC_DESC=		Use the tcmalloc memory allocation library
TOR2WEB_DESC=		Faster but non-anonymous hidden services
TRANSPARENT_DESC=	Transparent proxy support

OPTIONS_DEFAULT=	THREADS TRANSPARENT

USE_OPENSSL=	yes

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

GROUPS=		_tor
USERS=		_tor

CONFLICTS=	tor-devel-[0-9]*

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

.if !defined(USE_GCC) && empty(CC:T:M*gcc4*) && \
empty(PORT_OPTIONS:MSTATIC_TOR) && empty(ARCH:Mia64)
CONFIGURE_ARGS+=	--enable-gcc-hardening
.else
CONFIGURE_ARGS+=	--disable-gcc-hardening
.endif

.if ${PORT_OPTIONS:MBUFFEREVENTS}
CONFIGURE_ARGS+=	--enable-bufferevents
.else
CONFIGURE_ARGS+=	--disable-bufferevents
.endif

.if ${PORT_OPTIONS:MINSTR_DOWNLOADS}
CONFIGURE_ARGS+=	--enable-instrument-downloads
.else
CONFIGURE_ARGS+=	--disable-instrument-downloads
.endif

.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS +=	${LOCALBASE}/lib/libevent.a:devel/libevent2
CONFIGURE_ARGS+=	--enable-static-tor \
			--with-zlib-dir=/usr/lib --disable-linker-hardening
TOR_LIBEVENT_LIBS=	${LOCALBASE}/lib/libevent.a
.if ${PORT_OPTIONS:MBUFFEREVENTS}
TOR_LIBEVENT_LIBS:=	${LOCALBASE}/lib/libevent_openssl.a ${TOR_LIBEVENT_LIBS}
.endif
.else
CONFIGURE_ARGS+=	--enable-linker-hardening
LIB_DEPENDS+=		libevent.so:devel/libevent2
TOR_LIBEVENT_LIBS=	-levent
.if ${PORT_OPTIONS:MBUFFEREVENTS}
TOR_LIBEVENT_LIBS:=	-levent_openssl ${TOR_LIBEVENT_LIBS}
.endif
.endif

.if ${PORT_OPTIONS:MTCMALLOC}
CONFIGURE_ARGS+=	--with-tcmalloc
.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libtcmalloc.a:devel/google-perftools
.else
LIB_DEPENDS+=		libtcmalloc.so:devel/google-perftools
.endif
.endif

.if ${PORT_OPTIONS:MTOR2WEB}
CONFIGURE_ARGS+=	--enable-tor2web-mode
.endif

.if ${PORT_OPTIONS:MTRANSPARENT}
CONFIGURE_ARGS+=	--enable-transparent
.else
CONFIGURE_ARGS+=	--disable-transparent
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

post-configure:
	@${REINPLACE_CMD} -e '\|^nodist_man1_MANS =|s|$$|$$(install_mans:=.1)|' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}/var/log/tor ${STAGEDIR}/var/run/tor

.if ! ${PORT_OPTIONS:MTOR2WEB}
check regression-test test: build
	@cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	${MAKE_ARGS} check

.endif
.include <bsd.port.mk>
