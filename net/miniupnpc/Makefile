# $FreeBSD$

PORTNAME=	miniupnpc
PORTVERSION=	1.8
CATEGORIES?=	net
MASTER_SITES=	http://miniupnp.free.fr/files/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	UPnP IGD client lightweight library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE


HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	updateminiupnpcstrings.sh
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if ${SLAVE_PORT} == no
MAN3=		miniupnpc.3
USE_RC_SUBR=	miniupnpc
.endif

.include <bsd.port.post.mk>
