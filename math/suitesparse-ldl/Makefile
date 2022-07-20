PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.2.6
CATEGORIES=	math

COMMENT=	Simple LDL^T factorization

LICENSE=	LGPL21+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	LDL
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
