# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	CXSparse
PORTVERSION=	3.2.0
CATEGORIES=	math

COMMENT=	Extended version of CSparse

LICENSE=	LGPL21+

USES=		localbase:ldflags
OMP_NEEDED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
