# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	config
PORTVERSION=	${SSPVERSION}
CATEGORIES=	math

COMMENT=	Common library for SuiteSparse

LICENSE=	GPLv2+

OMP_NEEDED=	yes

BUILD_WRKSRC=	${WRKSRC}/SuiteSparse_config
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md	\
		${STAGEDIR}${DOCSDIR}/SuiteSparse_README.md

.include <bsd.port.post.mk>
