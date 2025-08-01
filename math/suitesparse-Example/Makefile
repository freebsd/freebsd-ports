PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	1.8.9
CATEGORIES=	math

COMMENT=	Examples for SuiteSparse
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libamd.so:math/suitesparse-amd				\
		libbtf.so:math/suitesparse-btf				\
		libcamd.so:math/suitesparse-camd			\
		libccolamd.so:math/suitesparse-ccolamd			\
		libcholmod.so:math/suitesparse-cholmod			\
		libcolamd.so:math/suitesparse-colamd			\
		libcxsparse.so:math/suitesparse-cxsparse		\
		libgraphblas.so:math/suitesparse-graphblas		\
		libklu_cholmod.so:math/suitesparse-klu			\
		liblagraph.so:math/suitesparse-lagraph			\
		libldl.so:math/suitesparse-ldl				\
		libsuitesparse_mongoose.so:math/suitesparse-mongoose	\
		libparu.so:math/suitesparse-paru			\
		librbio.so:math/suitesparse-rbio			\
		libspex.so:math/suitesparse-spex			\
		libspqr.so:math/suitesparse-spqr			\
		libumfpack.so:math/suitesparse-umfpack

USES=		localbase:ldflags fortran

MPORTNAME=	Example
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.md	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.md

.include <bsd.port.post.mk>
