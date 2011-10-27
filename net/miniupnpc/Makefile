# New ports collection makefile for:    miniupnpc
# Date created:         31 Oct 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	miniupnpc
PORTVERSION=	1.6
CATEGORIES?=	net
MASTER_SITES=	http://miniupnp.free.fr/files/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT?=	UPnP IGD client lightweight library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	updateminiupnpcstrings.sh
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}
CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if ${SLAVE_PORT} == no
MAN3=		miniupnpc.3

post-install:
	${INSTALL_MAN} ${WRKSRC}/man3/miniupnpc.3 ${PREFIX}/man/man3/
.endif

.include <bsd.port.post.mk>
