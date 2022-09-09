PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.9.6
CATEGORIES=	math

COMMENT=	Column approximate minimum degree ordering algorithm
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	COLAMD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
