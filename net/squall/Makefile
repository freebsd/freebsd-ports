# New ports collection makefile for:	squall
# Date created:		5 Apr 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	squall
PORTVERSION=	0.1.20040808
CATEGORIES=	net
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	${PORTNAME}-20040808

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Server for the Peer Distributed Transfer Protocol (PDTP)

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
STRIP=		# Keep empty for debugging.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squall/squall ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squallhub/squallhub ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squallproxy/squallproxy ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squirt/squirt ${PREFIX}/sbin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}

.include <bsd.port.mk>
