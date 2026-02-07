PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	5.3.4
CATEGORIES=	math

COMMENT=	Sparse CHOLesky MODification package
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	LGPL21+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd

USES=		localbase:ldflags

MPORTNAME=	CHOLMOD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${MPORTNAME}_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
