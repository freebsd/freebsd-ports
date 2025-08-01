PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	10.1.1
CATEGORIES=	math

COMMENT=	Graph algorithms in the language of linear algebra
WWW=		https://graphblas.org/

LICENSE=	APACHE20

USES=		localbase:ldflags pathfix

MPORTNAME=	GraphBLAS
CMAKE_ARGS+=	-DGRAPHBLAS_COMPACT:BOOL=On	\
		-DGRAPHBLAS_USE_JIT:BOOL=On
USE_LDCONFIG=	yes

PORTDOCS=	CSC20_OpenMP_GraphBLAS.pdf Davis_HPEC18.pdf	\
		GraphBLAS_API_C_v2.1.0.pdf	\
		GraphBLAS_UserGuide.pdf HPEC19.pdf	\
		HPEC20_Python_and_MATLAB.pdf lagraph-grapl19.pdf	\
		toms_graphblas.pdf toms_parallel_grb2.pdf	\
		The_GraphBLAS_in_Julia_and_Python_the_PageRank_and_Triangle_Centralities.pdf

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
