PORTNAME=	axom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Infrastructure for development of multi-physics applications and tools
WWW=		https://github.com/LLNL/axom \
		https://axom.readthedocs.io/en/develop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_armv7=	use of overloaded operator '[]' is ambiguous, see https://github.com/LLNL/axom/issues/743
BROKEN_i386=	use of overloaded operator '[]' is ambiguous, see https://github.com/LLNL/axom/issues/743
BROKEN_powerpc=	use of overloaded operator '[]' is ambiguous, see https://github.com/LLNL/axom/issues/743

LIB_DEPENDS=	libcamp.so:devel/camp \
		libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libHYPRE.so:science/hypre \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libRAJA.so:misc/raja \
		libsiloh5.so:science/silo \
		libumpire.so:devel/umpire
RUN_DEPENDS=	sparsehash>0:devel/sparsehash

USES=		cmake:testing,noninja compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	LLNL:axom_data:8ac544a:axom_data/../data \
		LLNL:blt:f08f95e:blt/cmake/blt \
		LLNL:uberenv:bec05e2:uberenv/../scripts/uberenv

CMAKE_OFF=	AXOM_ENABLE_DOCS AXOM_ENABLE_EXAMPLES AXOM_ENABLE_TESTS AXOM_ENABLE_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	AXOM_ENABLE_TESTS AXOM_ENABLE_EXAMPLES ENABLE_TESTS
CMAKE_TESTING_TARGET=	all test
CMAKE_ARGS=	-DCONDUIT_DIR=${LOCALBASE} \
		-DHDF5_DIR=${LOCALBASE} \
		-DBLT_CXX_STD=c++20

LDFLAGS+=	-lexecinfo

WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=		LUA MFEM OPENMP
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	LUA MFEM MPICH OPENMP     # LUA,MFEM,MPICH are required for LLNL/smith
OPTIONS_SUB=		yes

LUA_USES=		lua:53
LUA_CMAKE_ON=		-DLUA_DIR=${LUA_BASE} \
			-DFREEBSD_LUA_VER=${LUA_VER}

MFEM_DESC=		Use mfem - library for finite element methods
MFEM_CMAKE_ON=		-DMFEM_DIR=${LOCALBASE}
MFEM_LIB_DEPENDS=	libmfem.so:math/mfem

NOMPI_DESC=		Build without parallel processing support
NOMPI_BROKEN=		https://github.com/LLNL/axom/issues/913

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON

OPENMP_CMAKE_BOOL=	ENABLE_OPENMP
#OPENMP_BROKEN=		https://github.com/LLNL/axom/issues/911

post-install: # installs headers of a third party library sparsehash: https://github.com/LLNL/axom/issues/365
	@${RM} -r ${STAGEDIR}${PREFIX}/include/sparsehash

# tests as of 0.15.0: 99% tests passed, 2 tests failed out of 374 (slic_macros_parallel,
# primal_solid_angle are all floating-point-precision-sensitive failures with sub-ULP/tiny
# tolerance differences, or an MPI message-ordering race in the parallel logging test; not logic errors)

.include <bsd.port.mk>
