# New ports collection makefile for:	hping
# Date Created:				5 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	hping
PORTVERSION=	2.0.0r3
PORTEPOCH=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.hping.org/
DISTNAME=	hping2.0.0-rc3

MAINTAINER=	ecu@ipv42.net
COMMENT=	Network auditing tool

WRKSRC=		${WRKDIR}/hping2-rc3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--force-libpcap
USE_GMAKE=	yes

PLIST_FILES=	sbin/hping
PORTDOCS=	AS-BACKDOOR HPING2-HOWTO.txt HPING2-IS-OPEN \
		MORE-FUN-WITH-IPID SPOOFED_SCAN.txt APD.txt

MAN8=	hping.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${PREFIX}/man/man8/hping.8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
