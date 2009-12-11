# New ports collection makefile for:	iodine
# Date created:				Feb 15 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iodine
PORTVERSION=	0.5.2
CATEGORIES=	net
MASTER_SITES=	http://code.kryo.se/iodine/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tunnel IPv4 data through a DNS server

PLIST_FILES=	bin/iodine sbin/iodined

PORTDOCS=	CHANGELOG README TODO

MAN8=		iodine.8
MLINKS=		iodine.8 iodined.8

USE_RC_SUBR=	iodined

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodine ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodined ${PREFIX}/sbin
.for m in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${m} ${MANPREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
