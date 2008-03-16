# ports collection makefile for:	tor-devel
# Date created:				2005.10.20
# Whom:					peter.thoenen@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	tor
PORTVERSION=	0.1.2.19
CATEGORIES=	security net
MASTER_SITES=	http://www.torproject.org/dist/ \
		http://mirror.onionland.org/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivo+kw+ports.bfa274@is-root.com
COMMENT=	An anonymizing overlay network for TCP

RUN_DEPENDS=	tsocks:${PORTSDIR}/net/tsocks
LIB_DEPENDS=	event-1.3e:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

OPTIONS=	EVENTDNS "asynchronous DNS module" on \
		THREADS "multi-threading support" on \
		TRANSPARENT "transparent proxy support" on \
		VIDALIA "Vidalia graphical Tor controller" off

USE_RC_SUBR=	tor
SUB_FILES=	pkg-message

CONFLICTS=	tor-devel*

MANCOMPRESSED=	no
MAN1=		tor.1 tor-resolve.1 torify.1

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CPPFLAGS+=-I{LOCALBASE}/include \
		LDFLAGS+=-L{LOCALBASE}/lib

.if defined(WITH_EVENTDNS)
CONFIGURE_ARGS+=	--enable-eventdns
.else
CONFIGURE_ARGS+=	--disable-eventdns
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ENV+=	LDFLAGS+={PTHREAD_LIBS}
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
#fix typos in configure scripts, undesirable compiler flags, wrong location of in6.h
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E \
		-e 's!-g -O2!!' \
		-e 's!-O2!!' \
		-e 's|netintet|netinet|g' \
		-e 's|netinet/in6|netinet6/in6|g'

post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'

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

.include <bsd.port.post.mk>
