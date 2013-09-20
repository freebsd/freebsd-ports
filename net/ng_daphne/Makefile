# Created by: Gerasimos Dimitriadis
# $FreeBSD$

PORTNAME=	ng_daphne
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net kld
MASTER_SITES=	http://newton.ee.auth.gr/ng_daphne/ \
		LOCAL/glarkin

MAINTAINER=	gedimitr@auth.gr
COMMENT=	A simple netgraph module for multihop ad hoc networks

SSP_UNSAFE=	kernel module does not support ssp

.include <bsd.port.pre.mk>

SYSDIR?=	${SRC_BASE}/sys
.if !exists(${SYSDIR}/netgraph/netgraph.h)
IGNORE=		requires kernel source (/usr/src/sys) to build
.endif
MAKE_ENV+=	WERROR=

EXTRA_PATCHES=	${FILESDIR}/extra-patch-ng_daphne.c
PLIST_FILES=	lib/ng_daphne.ko
PORTDOCS=	README
SUB_FILES=	pkg-message

do-install:
	${INSTALL_KLD} ${WRKSRC}/ng_daphne.ko ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
