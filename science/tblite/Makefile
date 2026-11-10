PORTNAME=	tblite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Light-weight tight-binding framework
WWW=		https://tblite.readthedocs.io/ \
		https://github.com/tblite/tblite/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	mstore>0:science/mstore # unclear if this is really needed
LIB_DEPENDS=	libdftd4.so:science/dftd4 \
		libmctc-lib.so:science/mctc-lib \
		libmulticharge.so:science/multicharge \
		libopenblas.so:math/openblas \
		libs-dftd3.so:science/simple-dftd3 \
		libtoml-f.so:textproc/toml-f

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	TBLITE_WITH_TESTS
CMAKE_TESTING_ON=	TBLITE_WITH_TESTS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

# tests as of 0.8.0: 100% tests passed, 0 tests failed out of 36

.include <bsd.port.mk>
