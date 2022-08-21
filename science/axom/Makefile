PORTNAME=	axom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1-1671
DISTVERSIONSUFFIX=	-g88cac2607
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Infrastructure for development of multi-physics applications and tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_armv7=	use of overloaded operator '[]' is ambiguous, see https://github.com/LLNL/axom/issues/743
BROKEN_i386=	use of overloaded operator '[]' is ambiguous, see https://github.com/LLNL/axom/issues/743
BROKEN_powerpc=	use of overloaded operator '[]' is ambiguous, see https://github.com/LLNL/axom/issues/743

LIB_DEPENDS=	libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libsiloh5.so:science/silo \
		libsz.so:science/libaec
RUN_DEPENDS=	sparsehash>0:devel/sparsehash

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	LLNL:axom_data:b3d8e6f:axom_data/../data \
		LLNL:blt:ddd5a0c:blt/cmake/blt \
		LLNL:uberenv:a121a45:uberenv/scripts/uberenv

CMAKE_OFF=	AXOM_ENABLE_DOCS AXOM_ENABLE_EXAMPLES AXOM_ENABLE_TESTS AXOM_ENABLE_EXAMPLES
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	AXOM_ENABLE_TESTS
CMAKE_ARGS=	-DCONDUIT_DIR=${LOCALBASE} \
		-DHDF5_DIR=${LOCALBASE} \
		-DBLT_CXX_STD=c++14 # BLT_CXX_STD=c++14 is required for LLNL/serac

LDFLAGS+=	-lexecinfo

WRKSRC_SUBDIR=	src

CONFLICTS_INSTALL=	libfmt # bundles and installs an incompatible libfmt version: https://github.com/LLNL/axom/issues/561, axom headers include fmt unnecessarily

OPTIONS_DEFINE=		LUA MFEM MPI OPENMP
OPTIONS_DEFAULT=	LUA MFEM MPI #OPENMP     LUA,MFEM,MPI are required for LLNL/serac
OPTIONS_SUB=		yes

LUA_USES=		lua:54
LUA_CMAKE_ON=		-DLUA_DIR=${LUA_BASE} \
			-DFREEBSD_LUA_VER_STR=${LUA_VER_STR} \
			-DFREEBSD_LUA_VER=${LUA_VER}

MFEM_DESC=		Use mfem - library for finite element methods
MFEM_CMAKE_ON=		-DMFEM_DIR=${LOCALBASE}
MFEM_LIB_DEPENDS=	libmfem.so:math/mfem

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
MPI_RUN_DEPENDS=	openmpi>0:net/openmpi

OPENMP_CMAKE_BOOL=	ENABLE_OPENMP
OPENMP_BROKEN=		https://github.com/LLNL/axom/issues/911

post-install: # installs headers of a third party library sparsehash: https://github.com/LLNL/axom/issues/365
	@${RM} -r ${STAGEDIR}${PREFIX}/include/sparsehash

# 2 tests are known to fail, see https://github.com/LLNL/axom/issues/912

.include <bsd.port.mk>
