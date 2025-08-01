PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	6.3.6
CATEGORIES=	math

COMMENT=	Sparse multifrontal LU factorization
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv2+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd	\
		libcholmod.so:math/suitesparse-cholmod

USES=		localbase:ldflags

MPORTNAME=	UMFPACK
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${MPORTNAME}_QuickStart.pdf	\
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${MPORTNAME}_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
