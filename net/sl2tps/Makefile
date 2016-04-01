# Created by: Archie Cobbs
# $FreeBSD$

PORTNAME=	sl2tps
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/libpdel/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple L2TP server based on libpdel(3) and netgraph(4)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libpdel.so:devel/libpdel

USES=		uidfix

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${PREFIX}/include|$${LOCALBASE}/include|g ; \
		 /-g/s|^CFLAGS|#CFLAGS|g ; \
		 s|$${PREFIX}/lib|$${LOCALBASE}/lib|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
