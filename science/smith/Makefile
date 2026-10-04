PORTNAME=	smith
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High order nonlinear thermomechanical simulation code
WWW=		https://github.com/LLNL/smith

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaxom_core.so:science/axom \
		libcamp.so:devel/camp \
		libconduit.so:science/conduit \
		libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libHYPRE.so:science/hypre \
		libmetis.so:math/metis \
		libmfem.so:math/mfem \
		libopenblas.so:math/openblas \
		libsiloh5.so:science/silo

USES=		cmake:testing compiler:c++17-lang localbase:ldflags lua
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	smith
GH_TUPLE=	LLNL:blt:837a2630cc321573ac780befe2dfda1958095597:LLNL_blt/cmake/blt \
		LLNL:gretl:772a66663e532d9f458d855f043283a9211f61d5:LLNL_gretl/gretl \
		LLNL:uberenv:bf2f438fc1fe97bb8290a11e5d4f2d56085b4ee3:LLNL_uberenv/scripts/uberenv \
		LLNL:serac_tests:75d838c69f48a0f263ad68a81d963a0615bed37f:LLNL_serac_tests/tests

CMAKE_TESTING_ON=	ENABLE_TESTS

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_TESTS SMITH_ENABLE_CONTINUATION SMITH_ENABLE_TRIBOL
CMAKE_ARGS=	-DAXOM_DIR=${LOCALBASE} \
		-DCONDUIT_DIR=${LOCALBASE} \
		-DMFEM_DIR=${LOCALBASE} \
		-DHDF5_DIR=${LOCALBASE}

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH
OPTIONS_SUB=		yes

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON \
			-DMPI_C_COMPILER=${MPICC} \
			-DMPI_CXX_COMPILER=${MPICXX}

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON \
			-DMPI_C_COMPILER=${MPICC} \
			-DMPI_CXX_COMPILER=${MPICXX}
OPENMPI_BROKEN=		mixes OpenMPI and MPICH when both are installed, see https://github.com/LLNL/serac/issues/787

# tests as of 0.1.0: 72% tests passed, 27 tests failed out of 95 (most/all failures are SEGVs caused by the bug in math/superlu-dist, I narrowed it to this: https://github.com/xiaoyeli/superlu_dist/issues/227)

.include <bsd.port.mk>
