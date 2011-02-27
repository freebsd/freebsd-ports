# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					peter.thoenen@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
DISTVERSION=	0.2.2.22-alpha
PORTREVISION=	1
CATEGORIES=	security net ipv6
MASTER_SITES=	http://www.torproject.org/dist/ \
		ftp://tor.tomyn.com/pub/mirrors/tor/ \
		ftp://ftp.bit.nl/mirror/tor/ \
		http://tor-www.5coluna.com/dist/ \
		http://tor.amorphis.eu/dist/ \
		http://tor.askapache.com/dist/ \
		http://tor.beme-it.de/dist/ \
		http://tor.boinc.ch/dist/ \
		http://tor.ccc.de/dist/ \
		http://tor.idnr.ws/dist/ \
		http://tor.kamagurka.org/dist/ \
		http://torproj.xpdm.us/dist/ \
		http://www.oignon.net/dist/ \
		http://www.torproject.org.nyud.net/dist/ \
		http://www.torproject.us/dist/
PKGNAMESUFFIX=	-devel

MAINTAINER=	bf@FreeBSD.org
COMMENT=	An anonymizing overlay network for TCP

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-openssl-dir="${OPENSSLBASE}" --disable-asciidoc
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	BUFFREELISTS "freelists for buffer RAM" on \
		INSTR_DOWNLOADS "instrument downloads for analysis" off \
		TCMALLOC "use the tcmalloc memory allocation library" off \
		THREADS "multi-threading support" on \
		TRANSPARENT "transparent proxy support" on

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

CONFLICTS=	tor-[0-9]*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1 tor-gencert.1

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

.include <bsd.port.pre.mk>

.if  ( ${OSVERSION} < 704000 || \
(${OSVERSION} >= 800000 && ${OSVERSION} < 802000) || \
(${OSVERSION} >= 900000 && ${OSVERSION} < 900027) )
WITH_OPENSSL_PORT=	yes
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"

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
	@${REINPLACE_CMD} -e '\|CFLAGS=|{s|-g||;s|-O[0-9]\{0,1\}||;}' \
		-e 's|netinet/in6||g' ${WRKSRC}/configure

post-configure:
	@${FIND} -X ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		"s|-lpthread|${PTHREAD_LIBS}|g"
	@${REINPLACE_CMD} -e '\|^nodist_man_MANS =|s|$$|${MAN1}|' \
		${WRKSRC}/doc/Makefile

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

check regression-test test: build
	@( cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check )

.include <bsd.port.post.mk>
