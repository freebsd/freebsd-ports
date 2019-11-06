# $FreeBSD$

PORTNAME=	libpdtp
PORTVERSION=	0.1.20040808
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	${PORTNAME}-20040808

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Client library for Peer Distributed Transfer Protocol (PDTP)

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

USES=		ssl
WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-fpic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdtp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libpdtp.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libpdtp.so.0 ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
