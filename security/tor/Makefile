# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					peter.thoenen@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
DISTVERSION=	0.2.1.19
CATEGORIES=	security net ipv6
MASTER_SITES=	http://www.torproject.org/dist/ \
		http://tor.cypherpunks.at/dist/ \
		http://tor.depthstrike.com/dist/ \
		http://tor.boinc.ch/dist/ \
		http://tor.anonymity.cn/dist/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An anonymizing overlay network for TCP

RUN_DEPENDS=	tsocks:${PORTSDIR}/net/tsocks
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

OPTIONS=	BUFFREELISTS "freelists for buffer RAM" on \
		GEOIP "track country data" off \
		INSTR_DOWNLOADS "instrument downloads for analysis" off \
		TCMALLOC "use the tcmalloc memory allocation library" off \
		THREADS "multi-threading support" on \
		TRANSPARENT "transparent proxy support" on \
		VIDALIA "Vidalia graphical Tor controller" off

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

CONFLICTS=	tor-devel-[0-9]*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1 tor-gencert.1

.include <bsd.port.pre.mk>

.if defined(WITH_BUFFREELISTS)
CONFIGURE_ARGS+=	--enable-buf-freelists
.else
CONFIGURE_ARGS+=	--disable-buf-freelists
.endif

.if defined(WITH_GEOIP)
CONFIGURE_ARGS+=	--enable-geoip-stats
.else
CONFIGURE_ARGS+=	--disable-geoip-stats
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

.ifdef(WITH_VIDALIA)
RUN_DEPENDS+=	vidalia:${PORTSDIR}/net-mgmt/vidalia
.endif

post-patch:
	@${MV} ${WRKSRC}/contrib/tor-tsocks.conf \
		${WRKSRC}/contrib/tor-tsocks.conf.sample
	@${REINPLACE_CMD} -e "s|tor-tsocks.conf|tor-tsocks.conf.sample|g" \
		${WRKSRC}/contrib/Makefile.in
	@${FIND} -X ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E \
		-e 's|-g -O2||g' \
		-e 's|-O2||g' \
		-e 's|-g -O||g' \
		-e 's|netinet/in6|netinet6/in6|g'

post-configure:
	@${FIND} -X ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		"s|-lpthread|${PTHREAD_LIBS}|g"

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${MKDIR} /var/run/tor
	${CHOWN} _tor:_tor /var/run/tor
	${TOUCH} /var/log/tor
	${CHOWN} _tor:_tor /var/log/tor
	${MKDIR} /var/db/tor/data
	${CHOWN} _tor:_tor /var/db/tor
	${CAT} ${PKGMESSAGE}

regression-test: build
	@( cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check )

.include <bsd.port.post.mk>
