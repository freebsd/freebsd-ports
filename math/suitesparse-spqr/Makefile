# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	${MPORTNAME:tl}
PORTVERSION=	2.0.9
CATEGORIES=	math

COMMENT=	Sparse QR factorization

LICENSE=	GPLv2+

LIB_DEPENDS=	libamd.so:math/suitesparse-amd		\
		libcamd.so:math/suitesparse-camd	\
		libcolamd.so:math/suitesparse-colamd	\
		libccolamd.so:math/suitesparse-ccolamd	\
		libcholmod.so:math/suitesparse-cholmod

USES=		localbase:ldflags
BLAS_NEEDED=	yes
OMP_NEEDED=	yes

MPORTNAME=	SPQR
USE_LDCONFIG=	yes

# See https://github.com/DrTimothyAldenDavis/SuiteSparse/issues/72 and PR 252651
#OPTIONS_DEFINE+=	TBB
#OPTIONS_DEFAULT+=	TBB
#TBB_DESC=		Intel threading building blocks
#TBB_LIB_DEPENDS=	libtbb.so:devel/tbb
#TBB_MAKE_ENV=		TBB="-ltbb" SPQR_CONFIG="-DHAVE_TBB"

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
