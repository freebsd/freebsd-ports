PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.2.0
CATEGORIES=	math

COMMENT=	Extended version of CSparse

LICENSE=	LGPL21+

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	CXSparse
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
