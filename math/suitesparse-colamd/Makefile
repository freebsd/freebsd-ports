# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	COLAMD
PORTVERSION=	2.9.6
CATEGORIES=	math

COMMENT=	Column approximate minimum degree ordering algorithm

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags
OMP_NEEDED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
