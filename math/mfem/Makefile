PORTNAME=	mfem
DISTVERSIONPREFIX=	v
DISTVERSION=	4.10
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight, general, scalable C++ library for finite element methods
WWW=		https://mfem.org \
		https://github.com/mfem/mfem

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcc_s.so.1:lang/gcc14

USES=		blaslapack:openblas cmake:testing compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS MFEM_USE_LAPACK \
		MFEM_USE_ZLIB
CMAKE_TESTING_ON=	MFEM_ENABLE_TESTING # tests are broken, see https://github.com/mfem/mfem/issues/3163
CMAKE_TESTING_ARGS=	-DMFEM_ENABLE_TESTING:BOOL=ON

OPTIONS_DEFINE=		METIS SUPERLU
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	METIS MPICH SUPERLU # should be the same MPI choice as in science/hypre
OPTIONS_SUB=		yes

NOMPI_DESC=		Build without parallel processing support
OPENMPI_CMAKE_ON=	-DTPL_ENABLE_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DTPL_ENABLE_MPI=ON
MPICH_LIB_DEPENDS=	libHYPRE.so:science/hypre \
			libmetis.so:math/metis

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DTPL_ENABLE_MPI=ON
OPENMPI_LIB_DEPENDS=	libHYPRE.so:science/hypre \
			libmetis.so:math/metis

METIS_DESC=		Build with metis
METIS_CMAKE_BOOL=	MFEM_USE_METIS
METIS_LIB_DEPENDS=	libmetis.so:math/metis

SUPERLU_DESC=		Enable SuperLU use
SUPERLU_CMAKE_BOOL=	MFEM_USE_SUPERLU
SUPERLU_CMAKE_ON=	-DSuperLUDist_DIR=${LOCALBASE} -DSuperLUDist_INCLUDE_DIRS=${LOCALBASE}/include/superlu
SUPERLU_LIB_DEPENDS=	libsuperlu_dist.so:math/superlu-dist
SUPERLU_LDFLAGS=	-L${LOCALBASE}/lib -lsuperlu_dist # workaround for https://github.com/mfem/mfem/issues/3171#issuecomment-1236591028

post-install-SUPERLU-on: # workaround for https://github.com/mfem/mfem/issues/3191
	@${REINPLACE_CMD} \
		-e 's|;${LOCALBASE}/include/superlu||' \
		${STAGEDIR}${PREFIX}/lib/cmake/mfem/MFEMConfig.cmake

# the full testsuite fails and needs to be investigated: run a smoke test for now
do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_TESTING_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} exec && \
		cd examples && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ./ex1 -no-vis

# tests as of 4.10: serial smoke test (examples/ex1 -no-vis) completes successfully;
# see do-test comment above for why the full upstream ctest suite is not usable here

.include <bsd.port.mk>
