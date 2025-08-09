PORTNAME=	axom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
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

LIB_DEPENDS=	libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libHYPRE.so:science/hypre \
		libmetis.so:math/metis \
		libsiloh5.so:science/silo
RUN_DEPENDS=	sparsehash>0:devel/sparsehash

USES=		cmake:testing,noninja compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	LLNL:axom_data:1bff47e:axom_data/../data \
		LLNL:blt:9cfe8ae:blt/cmake/blt \
		LLNL:uberenv:e7dd3d9:uberenv/../scripts/uberenv

CMAKE_OFF=	AXOM_ENABLE_DOCS AXOM_ENABLE_EXAMPLES AXOM_ENABLE_TESTS AXOM_ENABLE_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	AXOM_ENABLE_TESTS AXOM_ENABLE_EXAMPLES
CMAKE_TESTING_TARGET=	all test
CMAKE_ARGS=	-DCONDUIT_DIR=${LOCALBASE} \
		-DHDF5_DIR=${LOCALBASE} \
		-DBLT_CXX_STD=c++14 # BLT_CXX_STD=c++14 is required for LLNL/serac

LDFLAGS+=	-lexecinfo

WRKSRC_SUBDIR=	src

CONFLICTS_INSTALL=	libfmt # bundles and installs an incompatible libfmt version: https://github.com/LLNL/axom/issues/561, axom headers include fmt unnecessarily

OPTIONS_DEFINE=		LUA MFEM OPENMP
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	LUA MFEM MPICH #OPENMP     LUA,MFEM,MPI are required for LLNL/serac
OPTIONS_SUB=		yes

LUA_USES=		lua:54
LUA_CMAKE_ON=		-DLUA_DIR=${LUA_BASE} \
			-DFREEBSD_LUA_VER_STR=${LUA_VER_STR} \
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
OPENMP_BROKEN=		https://github.com/LLNL/axom/issues/911

post-install: # installs headers of a third party library sparsehash: https://github.com/LLNL/axom/issues/365
	@${RM} -r ${STAGEDIR}${PREFIX}/include/sparsehash

# 2 tests are known to fail, see https://github.com/LLNL/axom/issues/912
# tests don't run in newer revisions, see https://github.com/LLNL/axom/issues/1492

.include <bsd.port.mk>
