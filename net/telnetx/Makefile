# New ports collection makefile for:	telnetx
# Date created:			22 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	telnetx
PORTVERSION=	940401
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	telnetx+transit.src.940401

MAINTAINER=	max@FreeBSD.org
COMMENT=	Telnet client with binary transfer protocols support

RUN_DEPENDS+=	bp:${PORTSDIR}/comms/bpl+
RUN_DEPENDS+=	kermit:${PORTSDIR}/comms/kermit

WRKSRC=		${WRKDIR}/telnetx
MAN1=		telnetx.1
ALL_TARGET=	bsdi

.if !exists(/usr/lib/libtelnet.a)
IGNORE=	"You need to make libtelnet first, which can be done in /usr/src/lib/libtelnet"
.if !exists(/usr/src/lib/libtelnet)
IGNORE+=". Oh dear, you don\'t have the sources installed neither"
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/telnet/telnet ${PREFIX}/bin/telnetx
	${INSTALL_PROGRAM} ${WRKSRC}/transit/transit ${PREFIX}/bin/transit
	${INSTALL_MAN} ${WRKSRC}/telnet/telnet.1 ${PREFIX}/man/man1/telnetx.1

.include <bsd.port.mk>
