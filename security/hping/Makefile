# New ports collection makefile for:	hping
# Date Created:				5 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	hping
PORTVERSION=	2b54
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.kyuzz.org/antirez/hping2-src/
DISTNAME=	hping2-beta54

MAINTAINER=	roman@xpert.com

BROKEN=		See PR 28974

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--force-libpcap

MAN8=	hping.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${PREFIX}/man/man8/hping.8
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hping
.for i in AS-BACKDOOR HPING2-HOWTO.txt HPING2-IS-OPEN MORE-FUN-WITH-IPID SPOOFED_SCAN.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${PREFIX}/share/doc/hping/
.endfor
.endif

.include <bsd.port.mk>
