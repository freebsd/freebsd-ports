PORTNAME=	serac
PORTVERSION=	g20220823
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High order nonlinear thermomechanical simulation code
WWW=		https://github.com/LLNL/serac

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaxom.so:science/axom \
		libconduit.so:science/conduit \
		libhdf5.so:science/hdf5 \
		libHYPRE.so:science/hypre \
		libmfem.so:math/mfem \
		libsiloh5.so:science/silo

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TAGNAME=	07b8ef1
GH_TUPLE=	LLNL:blt:49971b88e631aba76a9990c7702ceee47a7c3216:LLNL_blt/cmake/blt \
		LLNL:uberenv:2cd030dd8fa9ff381900bfbe12fe1eea44a57bb5:LLNL_uberenv/scripts/uberenv \
		LLNL:serac_tests:2fee9739eadeb218e99f7f5549e0800df81ca757:LLNL_serac_tests/tests

CMAKE_TESTING_ON=	ENABLE_TESTS # tests fail to compile, see https://github.com/LLNL/serac/issues/786

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_TESTS
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
