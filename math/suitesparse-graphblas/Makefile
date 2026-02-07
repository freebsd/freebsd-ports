PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	10.2.0
CATEGORIES=	math

COMMENT=	Graph algorithms in the language of linear algebra
WWW=		https://graphblas.org/

LICENSE=	APACHE20

USES=		localbase:ldflags pathfix

MPORTNAME=	GraphBLAS
CMAKE_ARGS+=	-DGRAPHBLAS_COMPACT:BOOL=On	\
		-DGRAPHBLAS_USE_JIT:BOOL=On
USE_LDCONFIG=	yes

PORTDOCS=	GraphBLAS_API_C_v2.1.0.pdf	\
		GraphBLAS_UserGuide.pdf

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
