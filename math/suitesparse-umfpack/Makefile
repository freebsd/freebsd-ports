# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	5.7.9
CATEGORIES=	math

COMMENT=	Sparse multifrontal LU factorization

LICENSE=	GPLv2+

LIB_DEPENDS=	libmetis.so:math/metis	\
		libamd.so:math/suitesparse-amd	\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd	\
		libcholmod.so:math/suitesparse-cholmod

USES=		localbase:ldflags
BLAS_NEEDED=	yes
OMP_NEEDED=	yes

MPORTNAME=	UMFPACK
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
