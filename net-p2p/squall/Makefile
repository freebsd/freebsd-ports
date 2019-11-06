# $FreeBSD$

PORTNAME=	squall
PORTVERSION=	0.1.20040808
CATEGORIES=	net-p2p
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	${PORTNAME}-20040808

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Server for the Peer Distributed Transfer Protocol (PDTP)

BROKEN=		unfetchable

USES=		ssl
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
STRIP=		# Keep empty for debugging.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squall/squall ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squallhub/squallhub ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squallproxy/squallproxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/squirt/squirt ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
