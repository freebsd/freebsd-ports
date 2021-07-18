# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	5.0.5
PORTREVISION=	1
CATEGORIES=	math

COMMENT=	Graph algorithms in the language of linear algebra

LICENSE=	APACHE20

USES=		cmake:insource localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	GraphBLAS
USE_LDCONFIG=	yes

PORTDOCS=	CSC20_OpenMP_GraphBLAS.pdf GraphBLAS_API_C_v13.pdf	\
		GraphBLAS_UserGuide.pdf HPEC19.pdf lagraph-grapl19.pdf	\
		toms_graphblas.pdf

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

pre-configure-OPENMP-off:
	${REINPLACE_CMD} -e '/find_package.*OpenMP/d' \
		${WRKSRC}/GraphBLAS/CMakeLists.txt

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
