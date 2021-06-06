# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	3.0.14
CATEGORIES=	math

COMMENT=	Sparse CHOLesky MODification package

LICENSE=	LGPL21+

LIB_DEPENDS=	libmetis.so:math/metis		\
		libamd.so:math/suitesparse-amd		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd

USES=		localbase:ldflags
BLAS_NEEDED=	yes
OMP_NEEDED=	yes

MPORTNAME=	CHOLMOD
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
