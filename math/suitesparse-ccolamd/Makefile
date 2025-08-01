PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.3.5
CATEGORIES=	math

COMMENT=	Constrained column approximate minimum degree ordering
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags

MPORTNAME=	CCOLAMD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt

.include <bsd.port.post.mk>
