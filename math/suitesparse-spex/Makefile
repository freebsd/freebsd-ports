PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.2.4
CATEGORIES=	math

COMMENT=	Sparse Left-looking Integer-Preserving LU Factorization
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv2+ LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE=	${BUILD_WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libamd.so:math/suitesparse-amd	\
		libcolamd.so:math/suitesparse-colamd

USES=		localbase:ldflags python
LDFLAGS+=	-lm

MPORTNAME=	SPEX
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.md	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.md
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/${MPORTNAME}_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
