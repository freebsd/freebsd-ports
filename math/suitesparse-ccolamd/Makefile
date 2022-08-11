PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.9.6
CATEGORIES=	math

COMMENT=	Constrained column approximate minimum degree ordering

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	CCOLAMD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
