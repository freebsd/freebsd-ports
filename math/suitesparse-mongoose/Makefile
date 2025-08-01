PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.3.5
CATEGORIES=	math

COMMENT=	Symmetric approximate minimum degree
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	GPLv3

USES=		cmake:insource localbase:ldflags pathfix python:test

MPORTNAME=	Mongoose
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	mongoose # bin/mongoose

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/Mongoose_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
