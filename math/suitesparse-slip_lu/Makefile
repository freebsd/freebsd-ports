PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	1.0.2
CATEGORIES=	math

COMMENT=	Sparse Left-looking Integer-Preserving LU Factorization

LICENSE=	GPLv2+ LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE=	${BUILD_WRKSRC}/License/license.txt

LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libamd.so:math/suitesparse-amd	\
		libcolamd.so:math/suitesparse-colamd

USES=		localbase:ldflags
OMP_NEEDED=	yes

MPORTNAME=	SLIP_LU
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
