# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.0.4
CATEGORIES=	math

COMMENT=	Symmetric approximate minimum degree

LICENSE=	GPLv3

USES=		cmake:insource localbase:ldflags

MPORTNAME=	Mongoose
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	mongoose # bin/mongoose

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/Doc/Mongoose_UserGuide.pdf	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
