PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.3.3
CATEGORIES=	math

COMMENT=	Permutation to block triangular form
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	LGPL21+

USES=		localbase:ldflags

MPORTNAME=	BTF
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt

.include <bsd.port.post.mk>
