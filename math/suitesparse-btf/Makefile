# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	BTF
PORTVERSION=	1.2.6
CATEGORIES=	math

COMMENT=	Permutation to block triangular form

LICENSE=	LGPL21+

USES=		localbase:ldflags
OMP_NEEDED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
