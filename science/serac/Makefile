PORTNAME=	serac
PORTVERSION=	g20260327
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High order nonlinear thermomechanical simulation code
WWW=		https://github.com/LLNL/smith

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaxom_core.so:science/axom \
		libcamp.so:devel/camp \
		libconduit.so:science/conduit \
		libgcc_s.so.1:lang/gcc14 \
		libhdf5.so:science/hdf5 \
		libHYPRE.so:science/hypre \
		libmetis.so:math/metis \
		libmfem.so:math/mfem \
		libopenblas.so:math/openblas \
		libsiloh5.so:science/silo

USES=		cmake:testing compiler:c++17-lang lua
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	smith
GH_TAGNAME=	887c1cb
GH_TUPLE=	LLNL:blt:2bf714a56d64b9b66b2a2b20207587af052efc36:LLNL_blt/cmake/blt \
		LLNL:gretl:fbbbee58b3d3b97771b107ca6e015a40dcf5e0f6:LLNL_gretl/gretl \
		LLNL:uberenv:bf2f438fc1fe97bb8290a11e5d4f2d56085b4ee3:LLNL_uberenv/scripts/uberenv \
		LLNL:serac_tests:75d838c69f48a0f263ad68a81d963a0615bed37f:LLNL_serac_tests/tests

CMAKE_TESTING_ON=	ENABLE_TESTS # tests fail to compile, see https://github.com/LLNL/serac/issues/786

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_TESTS SMITH_ENABLE_CONTINUATION
CMAKE_ARGS=	-DAXOM_DIR=${LOCALBASE} \
		-DCONDUIT_DIR=${LOCALBASE} \
		-DMFEM_DIR=${LOCALBASE}

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

.include <bsd.port.mk>
