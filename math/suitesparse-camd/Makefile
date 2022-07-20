PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.4.6
CATEGORIES=	math

COMMENT=	Symmetric approximate minimum degree

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	CAMD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
