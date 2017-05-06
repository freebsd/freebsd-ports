# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	tor
DISTVERSION=	0.3.0.6
CATEGORIES=	security net ipv6
MASTER_SITES=	TOR
PKGNAMESUFFIX=	-devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Anonymizing overlay network for TCP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips64=	Does not build: error: Need a uint128_t implementation!
BROKEN_powerpc64=	Does not build: error: Need a uint128_t implementation!
BROKEN_sparc64=	Does not build: error: Need a uint128_t implementation!

USES=		cpe gmake
CPE_VENDOR=	torproject
#CPE_VERSION=	${DISTVERSION:C/-.*//}
#CPE_UPDATE=	${DISTVERSION:C/.*-//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}"
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

OPTIONS_DEFINE=	MANPAGES STATIC_TOR TCMALLOC TOR2WEB TRANSPARENT
OPTIONS_SUB=	yes

STATIC_TOR_DESC=	Build a static tor
TCMALLOC_DESC=		Use the tcmalloc memory allocation library
TOR2WEB_DESC=		(EXPERT OPTION) Faster but non-anonymous hidden services
TRANSPARENT_DESC=	Transparent proxy support

OPTIONS_DEFAULT=	MANPAGES TRANSPARENT

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

GROUPS=		_tor
USERS=		_tor

CONFLICTS=	tor-[0-9]*

STATIC_TOR_USES=	ssl:build
STATIC_TOR_USES_OFF=	ssl

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc
MANPAGES_CONFIGURE_OFF=	--disable-asciidoc

.include <bsd.port.options.mk>

.if !defined(USE_GCC) && empty(CC:T:M*gcc4*) && \
empty(PORT_OPTIONS:MSTATIC_TOR) && empty(ARCH:Mia64)
CONFIGURE_ARGS+=	--enable-gcc-hardening
.else
CONFIGURE_ARGS+=	--disable-gcc-hardening
.endif

.if ${PORT_OPTIONS:MSTATIC_TOR}
BUILD_DEPENDS +=	${LOCALBASE}/lib/libevent.a:devel/libevent
CONFIGURE_ARGS+=	--enable-static-tor \
			--with-zlib-dir=/usr/lib --disable-linker-hardening
TOR_LIBEVENT_LIBS=	${LOCALBASE}/lib/libevent.a
.else
CONFIGURE_ARGS+=	--enable-linker-hardening
LIB_DEPENDS+=		libevent.so:devel/libevent
TOR_LIBEVENT_LIBS=	-levent
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

pre-everything::
.if ${PORT_OPTIONS:MTOR2WEB}
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: The expert option 'tor2web' is chosen."
	@${ECHO_MSG} "         With this option tor cannot be used for regular traffic,"
	@${ECHO_MSG} "         only for non-anonymous hidden service traffic."
	@${ECHO_MSG} "         Please make sure you understand this option."
	@${ECHO_MSG}
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
