# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					peter.thoenen@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
DISTVERSION=	0.2.2.33
PORTREVISION=	1
CATEGORIES=	security net ipv6
MASTER_SITES=	https://www.torproject.org/dist/ \
		ftp://ftp.bit.nl/mirror/tor/ \
		http://cyberside.net.ee/tor/ \
		http://mirrors.chaos-darmstadt.de/tor-mirror/dist/ \
		http://mirror.host4site.co.il/torproject.org/dist/ \
		http://mirror.tor.hu/dist/ \
		http://onion.anonymo.us.org/dist/ \
		http://theonionrouter.com/dist/ \
		http://tor.amorphis.eu/dist/ \
		http://tor.askapache.com/dist/ \
		http://tor.beme-it.de/dist/ \
		http://tor.blingblingsquad.net/dist/ \
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
		http://www.torproject.org.in/dist/ \
		http://www.oignon.net/dist/ \
		http://www.torproject.org.nyud.net/dist/ \
		http://www.torproject.us/dist/ \
		http://www.torservers.net/mirrors/torproject.org/dist/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	An anonymizing overlay network for TCP

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	event-2.0:${PORTSDIR}/devel/libevent2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-dir="${OPENSSLBASE}" --disable-asciidoc \
		--enable-linker-hardening
CONFIGURE_ENV=	TOR_CPPFLAGS_libevent="-I${LOCALBASE}/include/event2 -I${LOCALBASE}/include" \
		TOR_LDFLAGS_libevent="-L${LOCALBASE}/lib/event2" \
		TOR_LIBEVENT_LIBS="-levent-2.0"

OPTIONS=	BUFFREELISTS "freelists for buffer RAM" on \
		GMAKE "parallel build safety via GNU make" off \
		INSTR_DOWNLOADS "instrument downloads for analysis" off \
		TCMALLOC "use the tcmalloc memory allocation library" off \
		THREADS "multi-threading support" on \
		TRANSPARENT "transparent proxy support" on

USE_OPENSSL=	yes

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

GROUPS =	_tor
USERS=		_tor

CONFLICTS=	tor-devel-[0-9]*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1 tor-gencert.1

.include <bsd.port.options.mk>

.if defined(WITH_GMAKE)
USE_GMAKE=	yes
.else
MAKE_JOBS_UNSAFE=	yes
.endif

.if ( (${OSVERSION} >= 703100 && ${OSVERSION} < 800000) || \
(${OSVERSION} >= 800500 && ${OSVERSION} < 900000) || \
(${OSVERSION} >= 900003) ) && !defined(USE_GCC) && empty(CC:M*gcc4*)
CONFIGURE_ARGS+=	--enable-gcc-hardening
.endif

.if  ( ${OSVERSION} < 704000 || \
(${OSVERSION} >= 800000 && ${OSVERSION} < 801500) || \
(${OSVERSION} >= 900000 && ${OSVERSION} < 900011) )
WITH_OPENSSL_PORT=	yes
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

.if defined(WITH_TCMALLOC)
CONFIGURE_ARGS+=	--with-tcmalloc
LIB_DEPENDS+=		tcmalloc:${PORTSDIR}/devel/google-perftools
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
	@${REINPLACE_CMD} -e "s|-ltcmalloc|${LOCALBASE}/lib/libtcmalloc.so|" \
		${WRKSRC}/configure

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

.include <bsd.port.mk>
