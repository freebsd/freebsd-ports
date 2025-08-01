PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	1.2.0
CATEGORIES=	math

COMMENT=	Graph algorithms based on GraphBLAS
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgraphblas.so:math/suitesparse-graphblas

USES=		localbase:ldflags

MPORTNAME=	LAGraph
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.md	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.md

.include <bsd.port.post.mk>
