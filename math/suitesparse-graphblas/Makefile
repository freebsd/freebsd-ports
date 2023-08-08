PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	8.0.2
CATEGORIES=	math

COMMENT=	Graph algorithms in the language of linear algebra
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	APACHE20

USES=		localbase:ldflags

MPORTNAME=	GraphBLAS
USE_LDCONFIG=	yes

PORTDOCS=	CSC20_OpenMP_GraphBLAS.pdf GraphBLAS_API_C_v13.pdf	\
		GraphBLAS_UserGuide.pdf HPEC19.pdf lagraph-grapl19.pdf	\
		toms_graphblas.pdf

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
