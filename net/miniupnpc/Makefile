PORTNAME=	miniupnpc
PORTVERSION=	2.2.8
PORTREVISION=	0
CATEGORIES?=	net
MASTER_SITES=	http://miniupnp.free.fr/files/ \
		https://miniupnp.tuxfamily.org/files/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	UPnP IGD client lightweight library
WWW=		https://miniupnp.tuxfamily.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cpe gmake
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPE_VENDOR=	miniupnp_project

CONFIGURE_SCRIPT=	updateminiupnpcstrings.sh
MAKE_ENV+=	INSTALLPREFIX=${PREFIX} LIBDIR=lib
MAKE_ARGS+=	MANPATH="${PREFIX}/share/man"

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if ${SLAVE_PORT} == no
USE_RC_SUBR=	miniupnpc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/upnpc \
		${STAGEDIR}${PREFIX}/bin/upnp-listdevices \
		${STAGEDIR}${PREFIX}/lib/libminiupnpc.so.18
.endif

.include <bsd.port.post.mk>
