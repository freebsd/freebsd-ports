# New ports collection makefile for:	ng_daphne
# Date created:		8 November 2003
# Whom:			Gerasimos Dimitriadis
#
# $FreeBSD$
#

PORTNAME=	ng_daphne
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://newton.ee.auth.gr/ng_daphne/

MAINTAINER=	gedimitr@auth.gr
COMMENT=	A simple netgraph module for multihop ad hoc networks

.include <bsd.port.pre.mk>

BROKEN=		"Does not compile"

.if !exists(/usr/src/sys/netgraph/netgraph.h)
IGNORE=		"Requires kernel source /usr/src/sys to build"
.endif

.if ${OSVERSION} < 500000
IGNORE=		"Requires new netgraph architecture ng_item to build"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng_daphne.ko ${PREFIX}/lib
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
