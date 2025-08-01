PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.3.3
CATEGORIES=	math

COMMENT=	Simple LDL^T factorization
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	LGPL21+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd

USES=		localbase:ldflags

MPORTNAME=	LDL
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/ldl_userguide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
