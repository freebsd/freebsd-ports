# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					peter.thoenen@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
DISTVERSION=	0.2.3.2-alpha
CATEGORIES=	security net ipv6
MASTER_SITES=	https://www.torproject.org/dist/ \
		ftp://ftp.bit.nl/mirror/tor/ \
		http://cyberside.net.ee/tor/ \
		http://mirrors.chaos-darmstadt.de/tor-mirror/dist/ \
		http://mirror.tor.hu/dist/ \
		http://onion.anonymo.us.org/dist/ \
		http://theonionrouter.com/dist/ \
		http://tor-www.5coluna.com/dist/ \
		http://tor.amorphis.eu/dist/ \
		http://tor.askapache.com/dist/ \
		http://tor.beme-it.de/dist/ \
		http://tor.ccc.de/dist/ \
		http://tor.cyberarmy.at/dist/ \
		http://tor.homosu.net/dist/ \
		http://tor.idnr.ws/dist/ \
		http://tor.kamagurka.org/dist/ \
		http://tor.searchprivate.com/dist/ \
		http://tor.taiga-san.net/dist/ \
		http://tor.webersiedlung.at/dist/ \
		http://tordistua.reactor-xg.kiev.ua/ \
		http://torproj.xpdm.us/dist/ \
		http://torproject.nwlinux.us/dist/ \
		http://www.oignon.net/dist/ \
		http://www.torproject.org.nyud.net/dist/ \
		http://www.torproject.us/dist/ \
		http://www.torservers.net/mirrors/torproject.org/dist/
PKGNAMESUFFIX=	-devel

MAINTAINER=	bf@FreeBSD.org
COMMENT=	An anonymizing overlay network for TCP

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}" --disable-asciidoc
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" \
		TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include/event2 -I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/event2" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

MAKE_JOBS_UNSAFE=	yes

OPTIONS=	BUFFEREVENTS "use libevent's buffered IO" off \
		BUFFREELISTS "freelists for buffer RAM" on \
		INSTR_DOWNLOADS "instrument downloads for analysis" off \
		STATIC_TOR "build a static tor" off \
		TCMALLOC "use the tcmalloc memory allocation library" off \
		THREADS "multi-threading support" on \
		TRANSPARENT "transparent proxy support" on

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

GROUPS =	_tor
USERS=		_tor

CONFLICTS=		tor-[0-9]*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1 tor-gencert.1

.include <bsd.port.pre.mk>

.if  ( ${OSVERSION} < 704000 || \
(${OSVERSION} >= 800000 && ${OSVERSION} < 802000) || \
(${OSVERSION} >= 900000 && ${OSVERSION} < 900027) )
WITH_OPENSSL_PORT=	yes
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"

.if defined(WITH_BUFFEREVENTS)
BROKEN =	there are unresolved problems with BUFFEREVENTS; please disable this option
CONFIGURE_ARGS+=	--enable-bufferevents
.else
CONFIGURE_ARGS+=	--disable-bufferevents
.endif

.if defined(WITH_BUFFREELISTS)
CONFIGURE_ARGS+=	--enable-buf-freelists
.else
CONFIGURE_ARGS+=	--disable-buf-freelists
.endif

.if defined(WITH_INSTR_DOWNLOADS)
CONFIGURE_ARGS+=	--enable-instrument-downloads
.else
CONFIGURE_ARGS+=	--disable-instrument-downloads
.endif

.if defined(WITH_STATIC_TOR)
BUILD_DEPENDS +=	${LOCALBASE}/lib/event2/libevent.a:${PORTSDIR}/devel/libevent2
CONFIGURE_ARGS+=	--enable-static-tor --with-libevent-dir=${LOCALBASE}/lib/event2 \
			--with-zlib-dir=/usr/lib
TOR_LIBEVENT_LIBS=	${LOCALBASE}/lib/event2/libevent.a
.if defined(WITH_BUFFEREVENTS)
TOR_LIBEVENT_LIBS:=	${LOCALBASE}/lib/event2/libevent_openssl.a ${TOR_LIBEVENT_LIBS}
.endif
.else
CONFIGURE_ARGS+=	--enable-linker-hardening
LIB_DEPENDS+=		event-2.0:${PORTSDIR}/devel/libevent2
TOR_LIBEVENT_LIBS=	-levent-2.0
.if defined(WITH_BUFFEREVENTS)
TOR_LIBEVENT_LIBS:=	-levent_openssl-2.0 ${TOR_LIBEVENT_LIBS}
.endif
.endif

.if defined(WITH_TCMALLOC)
CONFIGURE_ARGS+=	--with-tcmalloc
.if defined(WITH_STATIC_TOR)
BUILD_DEPENDS +=	${LOCALBASE}/lib/libtcmalloc.so:${PORTSDIR}/devel/google-perftools
.else
LIB_DEPENDS+=		tcmalloc:${PORTSDIR}/devel/google-perftools
.endif
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
CFLAGS+=		${PTHREAD_CFLAGS}
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if defined(WITH_TRANSPARENT)
CONFIGURE_ARGS+=	--enable-transparent
.else
CONFIGURE_ARGS+=	--disable-transparent
.endif

post-patch:
	@${MV} ${WRKSRC}/contrib/tor-tsocks.conf \
		${WRKSRC}/contrib/tor-tsocks.conf.sample
	@${REINPLACE_CMD} -e "s|tor-tsocks.conf|tor-tsocks.conf.sample|g" \
		${WRKSRC}/contrib/Makefile.in
	@${REINPLACE_CMD} -e '\|^install-data-am:|s|install-docDATA||' \
		${WRKSRC}/doc/Makefile.in

post-configure:
	@${FIND} -X ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		"s|-lpthread|${PTHREAD_LIBS}|g"
	@${REINPLACE_CMD} -e '\|^nodist_man_MANS =|s|$$|${MAN1}|' \
		${WRKSRC}/doc/Makefile

post-install:
	${MKDIR} /var/run/tor
	${CHOWN} -R _tor:_tor /var/run/tor
	${TOUCH} /var/log/tor
	${CHOWN} _tor:_tor /var/log/tor
	${MKDIR} /var/db/tor/data
	${CHOWN} -R _tor:_tor /var/db/tor
	${CHMOD} -R 700 /var/db/tor
	${CAT} ${PKGMESSAGE}

check regression-test test: build
	@( cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check )

.include <bsd.port.post.mk>
