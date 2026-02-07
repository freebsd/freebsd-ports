PORTNAME=	bliss
DISTVERSION=	0.73
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.tcs.hut.fi/Software/bliss/
PKGNAMESUFFIX=	-graph-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for computing automorphism groups and canonical forms of graphs
WWW=		http://www.tcs.hut.fi/Software/bliss/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake zip

MAKE_ARGS=	CC=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libbliss.so ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${CP} ${WRKSRC}/*.hh ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
