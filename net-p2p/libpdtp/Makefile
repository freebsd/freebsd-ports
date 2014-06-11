# $FreeBSD$

PORTNAME=	libpdtp
PORTVERSION=	0.1.20040808
CATEGORIES=	net-p2p
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	${PORTNAME}-20040808

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Client library for Peer Distributed Transfer Protocol (PDTP)

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-fpic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdtp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libpdtp.* ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
