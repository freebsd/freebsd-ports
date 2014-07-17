# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	tor
DISTVERSION=	0.2.5.5-alpha
CATEGORIES=	security net ipv6
MASTER_SITES=	TOR
PKGNAMESUFFIX=	-devel

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Anonymizing overlay network for TCP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}" --disable-asciidoc
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include/event2 -I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/event2" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

OPTIONS_DEFINE=	BUFFEREVENTS BUFFREELISTS INSTR_DOWNLOADS MEMPOOLS \
		STATIC_TOR TCMALLOC THREADS TOR2WEB TRANSPARENT

BUFFEREVENTS_DESC=	Use libevent's buffered IO
BUFFREELISTS_DESC=	Freelists for buffer RAM
INSTR_DOWNLOADS_DESC=	Instrument downloads for analysis
MEMPOOLS_DESC=		Mempools for relay cells
STATIC_TOR_DESC=	Build a static tor
TCMALLOC_DESC=		Use the tcmalloc memory allocation library
TOR2WEB_DESC=		Faster but non-anonymous hidden services
TRANSPARENT_DESC=	Transparent proxy support

OPTIONS_DEFAULT=	THREADS TRANSPARENT

USE_OPENSSL=	yes

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

GROUPS =	_tor
USERS=		_tor

CONFLICTS=	tor-[0-9]*

.include <bsd.port.options.mk>

.if ( (${OSVERSION} < 900000) || \
(${OSVERSION} >= 900003) ) && !defined(USE_GCC) && empty(CC:T:M*gcc4*) && \
empty(PORT_OPTIONS:MSTATIC_TOR) && empty(ARCH:Mia64)
CONFIGURE_ARGS+=	--enable-gcc-hardening
.else
CONFIGURE_ARGS+=	--disable-gcc-hardening
.endif

.if ${PORT_OPTIONS:MBUFFEREVENTS}
CONFIGURE_ARGS+=	--enable-bufferevents
BROKEN=	some functions are hidden from the test binaries that use them WITH_BUFFEREVENTS
.else
CONFIGURE_ARGS+=	--disable-bufferevents
.endif

.if ${PORT_OPTIONS:MBUFFREELISTS}
CONFIGURE_ARGS+=	--enable-buf-freelists
.else
CONFIGURE_ARGS+=	--disable-buf-freelists
.endif

.if ${PORT_OPTIONS:MINSTR_DOWNLOADS}
CONFIGURE_ARGS+=	--enable-instrument-downloads
.else
CONFIGURE_ARGS+=	--disable-instrument-downloads
.endif

.if ${PORT_OPTIONS:MMEMPOOLS}
CONFIGURE_ARGS+=	--enable-mempools
.else
CONFIGURE_ARGS+=	--disable-mempools
.endif

.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS +=	${LOCALBASE}/lib/event2/libevent.a:${PORTSDIR}/devel/libevent2
CONFIGURE_ARGS+=	--enable-static-tor --with-libevent-dir=${LOCALBASE}/lib/event2 \
			--with-zlib-dir=/usr/lib --disable-linker-hardening
TOR_LIBEVENT_LIBS=	${LOCALBASE}/lib/event2/libevent.a
.if ${PORT_OPTIONS:MBUFFEREVENTS}
TOR_LIBEVENT_LIBS:=	${LOCALBASE}/lib/event2/libevent_openssl.a ${TOR_LIBEVENT_LIBS}
.endif
.else
CONFIGURE_ARGS+=	--enable-linker-hardening
LIB_DEPENDS+=		libevent-2.0.so:${PORTSDIR}/devel/libevent2
TOR_LIBEVENT_LIBS=	-levent-2.0
.if ${PORT_OPTIONS:MBUFFEREVENTS}
TOR_LIBEVENT_LIBS:=	-levent_openssl-2.0 ${TOR_LIBEVENT_LIBS}
.endif
.endif

.if ${PORT_OPTIONS:MTCMALLOC}
CONFIGURE_ARGS+=	--with-tcmalloc
.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS +=	${LOCALBASE}/lib/libtcmalloc.so:${PORTSDIR}/devel/google-perftools
.else
LIB_DEPENDS+=		libtcmalloc.so:${PORTSDIR}/devel/google-perftools
.endif
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
CFLAGS+=		${PTHREAD_CFLAGS}
.else
CONFIGURE_ARGS+=	--disable-threads
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
	@${REINPLACE_CMD} -E -e "s@-ltcmalloc@${LOCALBASE}/lib/libtcmalloc.so@" \
		-e "s@(-z) (relro|now)@-Wl,\1,\2@g" \
		${WRKSRC}/configure

post-configure:
	@${FIND} -X ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		"s|-lpthread|${PTHREAD_LIBS}|g"
	@${REINPLACE_CMD} -e '\|^nodist_man1_MANS =|s|$$|$$(install_mans:=.1)|' \
		${WRKSRC}/Makefile

.if ! ${PORT_OPTIONS:MTOR2WEB}
check regression-test test: build
	@cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	${MAKE_ARGS} check

.endif
.include <bsd.port.mk>
