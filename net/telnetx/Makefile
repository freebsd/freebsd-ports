# New ports collection makefile for:	telnetx
# Version required:		?
# Date created:			22 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1996/11/13 12:41:28 asami Exp $
#

DISTNAME=	telnetx+transit.src.940401
PKGNAME=	telnetx-940401
CATEGORIES=	net
MASTER_SITES=	ftp://freefall.FreeBSD.ORG/pub/FreeBSD/LOCAL_PORTS/ \
		http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	rz:${PORTSDIR}/comms/rzsz
RUN_DEPENDS+=	bp:${PORTSDIR}/comms/bpl+
RUN_DEPENDS+=	kermit:${PORTSDIR}/comms/kermit/

WRKSRC=		${WRKDIR}/telnetx
MAN1=		telnetx.1
ALL_TARGET=	bsdi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/telnet/telnet ${PREFIX}/bin/telnetx
	${INSTALL_PROGRAM} ${WRKSRC}/transit/transit ${PREFIX}/bin/transit
	${INSTALL_MAN} ${WRKSRC}/telnet/telnet.1 ${PREFIX}/man/man1/telnetx.1

.include <bsd.port.mk>
