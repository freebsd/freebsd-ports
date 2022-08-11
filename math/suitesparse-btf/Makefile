PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	1.2.6
CATEGORIES=	math

COMMENT=	Permutation to block triangular form

LICENSE=	LGPL21+

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	BTF
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
