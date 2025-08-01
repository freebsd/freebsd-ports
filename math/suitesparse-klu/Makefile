PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.3.6
CATEGORIES=	math

COMMENT=	Sparse LU factorization, for circuit simulation
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	LGPL21+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd		\
		libbtf.so:math/suitesparse-btf		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd	\
		libcholmod.so:math/suitesparse-cholmod

USES=		localbase:ldflags
CMAKE_ARGS+=	-DNSTATIC:BOOL=off

MPORTNAME=	KLU
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${MPORTNAME}_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
