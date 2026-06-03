PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.3.4
CATEGORIES=	math

COMMENT=	Symmetric approximate minimum degree
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags fortran

MPORTNAME=	AMD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/AMD_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
