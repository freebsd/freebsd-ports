PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	4.3.5
CATEGORIES=	math

COMMENT=	Sparse QR factorization
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv2+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd	\
		libcholmod.so:math/suitesparse-cholmod

USES=		localbase:ldflags

MPORTNAME=	SPQR
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/spqr_user_guide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
