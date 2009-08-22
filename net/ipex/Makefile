# New ports collection makefile for:    ipex
# Date created:         5 January 2002
# Whom:                 C.S. Peron <maneo@bsdpro.com>
#
# $FreeBSD$
#

PORTNAME=	ipex
PORTVERSION=	3.0
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	csjp@FreeBSD.org
COMMENT=	Packet examination / sniffer utility

MAN1=		ipex.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/ipex

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipex ${PREFIX}/bin/ipex
	${INSTALL_MAN} ${WRKSRC}/doc/ipex.1.gz ${MANPREFIX}/man/man1/ipex.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
