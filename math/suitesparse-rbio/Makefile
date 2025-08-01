PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	4.3.5
CATEGORIES=	math

COMMENT=	Read/write sparse matrices
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv2+

USES=		localbase:ldflags

MPORTNAME=	RBio
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.txt

.include <bsd.port.post.mk>
