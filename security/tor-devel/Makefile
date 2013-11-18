# Created by: peter.thoenen@yahoo.com
# $FreeBSD$

PORTNAME=	tor
DISTVERSION=	0.2.4.18-rc
CATEGORIES=	security net ipv6
MASTER_SITES=	https://www.torproject.org/dist/ \
		ftp://ftp.bit.nl/mirror/tor/ \
		http://cyberside.net.ee/tor/ \
		http://ftp.bit.nl/mirror/tor/ \
		http://mirror.hessmo.com/tor/dist/ \
		http://mirror.host4site.co.il/torproject.org/dist/ \
		http://mirror.open-networx.org/torproject.org/dist/ \
		http://mirror.tor.hu/dist/ \
		https://mirror.torland.me/torproject.org/dist/ \
		http://mirrors.chaos-darmstadt.de/tor-mirror/dist/ \
		http://theonionrouter.com/dist/ \
		http://tor.amorphis.eu/dist/ \
		http://tor.askapache.com/dist/ \
		http://tor.beme-it.de/dist/ \
		http://tor.blingblingsquad.net/dist/ \
		http://tor.borgmann.tv/dist/ \
		http://tor.ccc.de/dist/ \
		http://tor.cyberarmy.at/dist/ \
		http://tor.dont-know-me.at/dist/ \
		http://tor.homosu.net/dist/ \
		http://tor.idnr.ws/dist/ \
		http://tor.myrl.net/dist/ \
		http://tor.kamagurka.org/dist/ \
		http://tor.spline.de/dist/ \
		http://tor.taiga-san.net/dist/ \
		http://tor.vesta.nu/dist/ \
		http://torproj.xpdm.us/dist/ \
		https://torproject.antagonism.org/dist/ \
		https://torproject.crypto.is/dist/ \
		http://torproject.is/dist/ \
		http://torproject.jcsh.it/dist/ \
		http://torproject.nwlinux.us/dist/ \
		http://torproject.ph3x.at/dist/ \
		https://www.coevoet.nl/tor/dist/ \
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
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include/event2 -I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/event2" \
		TOR_LIBEVENT_LIBS="${TOR_LIBEVENT_LIBS}"

OPTIONS_DEFINE=	BUFFEREVENTS BUFFREELISTS GMAKE INSTR_DOWNLOADS \
		STATIC_TOR TCMALLOC THREADS TOR2WEB TRANSPARENT

BUFFEREVENTS_DESC=	Use libevent's buffered IO
BUFFREELISTS_DESC=	Freelists for buffer RAM
GMAKE_DESC=		Parallel build safety via GNU make
INSTR_DOWNLOADS_DESC=	Instrument downloads for analysis
STATIC_TOR_DESC=	Build a static tor
TCMALLOC_DESC=		Use the tcmalloc memory allocation library
TOR2WEB_DESC=		Faster but non-anonymous hidden services
TRANSPARENT_DESC=	Transparent proxy support

OPTIONS_DEFAULT=	BUFFREELISTS THREADS TRANSPARENT

USE_OPENSSL=	yes

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

GROUPS =	_tor
USERS=		_tor

CONFLICTS=	tor-[0-9]*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1 tor-gencert.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMAKE}
USES+=			gmake
.else
MAKE_JOBS_UNSAFE=	yes
.endif

.if ( (${OSVERSION} >= 703100 && ${OSVERSION} < 800000) || \
(${OSVERSION} >= 800500 && ${OSVERSION} < 900000) || \
(${OSVERSION} >= 900003) ) && !defined(USE_GCC) && empty(CC:T:M*gcc4*) && \
empty(PORT_OPTIONS:MSTATIC_TOR) && empty(ARCH:Mia64)
CONFIGURE_ARGS+=	--enable-gcc-hardening
.else
CONFIGURE_ARGS+=	--disable-gcc-hardening
.endif

.if  ( ${OSVERSION} < 704000 || \
(${OSVERSION} >= 800000 && ${OSVERSION} < 802000) || \
(${OSVERSION} >= 900000 && ${OSVERSION} < 900027) )
WITH_OPENSSL_PORT=	yes
.endif

.if  ( ${OSVERSION} < 800038 )
CPPFLAGS+=	-DSTAILQ_ENTRY=SIMPLEQ_ENTRY
.endif

.if ${PORT_OPTIONS:MBUFFEREVENTS}
CONFIGURE_ARGS+=	--enable-bufferevents
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
	@${REINPLACE_CMD} -e '\|^nodist_man1_MANS =|s|$$|${MAN1:S@^@doc/@}|' \
		${WRKSRC}/Makefile

post-install:
	${MKDIR} /var/run/tor
	${CHOWN} -R _tor:_tor /var/run/tor
	${TOUCH} /var/log/tor
	${CHOWN} _tor:_tor /var/log/tor
	${MKDIR} /var/db/tor/data
	${CHOWN} -R _tor:_tor /var/db/tor
	${CHMOD} -R 700 /var/db/tor
	${CAT} ${PKGMESSAGE}

.if empty(PORT_OPTIONS:MTOR2WEB)
check regression-test test: build
	@cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.endif
.include <bsd.port.mk>
