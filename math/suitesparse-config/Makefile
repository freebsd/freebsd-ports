PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	${SSPVERSION}
PORTREVISION=	1
CATEGORIES=	math

COMMENT=	Common library for SuiteSparse
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv2+

MPORTNAME=	config
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md	\
		${STAGEDIR}${DOCSDIR}/SuiteSparse_README.md
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.txt	\
		${STAGEDIR}${DOCSDIR}/${PORTNAME}_README.txt

.include <bsd.port.post.mk>
