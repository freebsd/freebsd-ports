# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	KLU
PORTVERSION=	1.3.9
CATEGORIES=	math

COMMENT=	Sparse LU factorization, for circuit simulation

LICENSE=	LGPL21+

LIB_DEPENDS=	libmetis.so:math/metis		\
		libamd.so:math/suitesparse-amd		\
		libbtf.so:math/suitesparse-btf		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd	\
		libcholmod.so:math/suitesparse-cholmod

USES=		localbase:ldflags
OMP_NEEDED=	yes
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
