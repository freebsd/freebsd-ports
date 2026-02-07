PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	4.4.2
CATEGORIES=	math

COMMENT=	Extended version of CSparse
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	LGPL21+

USES=		localbase:ldflags

MPORTNAME=	CXSparse
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt

.include <bsd.port.post.mk>
