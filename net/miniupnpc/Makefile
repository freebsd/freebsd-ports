# $FreeBSD$

PORTNAME=	miniupnpc
PORTVERSION=	2.0.20161216
CATEGORIES?=	net
MASTER_SITES=	http://miniupnp.free.fr/files/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	UPnP IGD client lightweight library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		gmake
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	updateminiupnpcstrings.sh
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if ${SLAVE_PORT} == no
USE_RC_SUBR=	miniupnpc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/upnpc \
		${STAGEDIR}${PREFIX}/lib/libminiupnpc.so.16
.endif

.include <bsd.port.post.mk>
