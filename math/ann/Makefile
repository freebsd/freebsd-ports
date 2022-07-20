PORTNAME=	ann
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	http://www.cs.umd.edu/~mount/ANN/Files/1.1.2/
DISTNAME=	ann_1.1.2

MAINTAINER=	tzhuan@csie.org
COMMENT=	Library for Approximate Nearest Neighbor Searching

USE_LDCONFIG=	yes
USES=		gmake

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libann.so.0 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libann.a ${STAGEDIR}${PREFIX}/lib
	${LN} -fs libann.so.0 ${STAGEDIR}${PREFIX}/lib/libann.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/ANN
	${INSTALL_DATA} ${WRKSRC}/include/ANN/* ${STAGEDIR}${PREFIX}/include/ANN
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ANNmanual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
