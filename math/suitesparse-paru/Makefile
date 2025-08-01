PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	1.0.1
CATEGORIES=	math parallel

COMMENT=	Parallel unsymmetric multifrontal method
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv3

LIB_DEPENDS=	libumfpack.so:math/suitesparse-umfpack

USES=		localbase
CMAKE_ARGS+=	-DUMFPACK_DIR:PATH="${LOCALBASE}/lib/cmake/UMFPACK"

MPORTNAME=	ParU
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/README.md	\
		${STAGEDIR}${DOCSDIR}/${MPORTNAME}_README.md
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/paru_user_guide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
