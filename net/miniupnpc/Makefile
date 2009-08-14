# New ports collection makefile for:    miniupnpc
# Date created:         31 Oct 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	miniupnpc
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES?=	net
MASTER_SITES=	http://miniupnp.free.fr/files/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT?=	UPnP IGD client lightweight library

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	updateminiupnpcstrings.sh
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}
CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if !defined(SLAVE_PORT)
MAN3=		miniupnpc.3
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if !defined(SLAVE_PORT)
post-install:
	${INSTALL_MAN} ${WRKSRC}/man3/miniupnpc.3 ${PREFIX}/man/man3/
.endif

.include <bsd.port.post.mk>
