# $FreeBSD$

PORTNAME=	squall
PORTVERSION=	0.1.20040808
CATEGORIES=	net-p2p
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	${PORTNAME}-20040808

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Server for the Peer Distributed Transfer Protocol (PDTP)

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
STRIP=		# Keep empty for debugging.

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squall/squall ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squallhub/squallhub ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squallproxy/squallproxy ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squirt/squirt ${PREFIX}/sbin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}

.include <bsd.port.mk>
