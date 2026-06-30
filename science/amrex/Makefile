PORTNAME=	amrex
DISTVERSION=	26.06
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AMReX: Software Framework for Block Structured AMR
WWW=		https://amrex-codes.github.io/index.html \
		https://github.com/AMReX-Codes/amrex

LICENSE=	APACHE20

USES=		cmake:testing compiler:c++20-lang perl5 python shebangfix
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AMReX-Codes

SHEBANG_GLOB=	*.pl *.py
SHEBANG_FILES=	Tools/C_scripts/mkdep

CMAKE_ON=	BUILD_SHARED_LIBS \
		AMReX_PIC
CMAKE_OFF=	AMReX_ENABLE_TESTS

CMAKE_TESTING_ON=	AMReX_ENABLE_TESTS


OPTIONS_GROUP=			PARALLEL PACKAGES
OPTIONS_GROUP_PARALLEL=		MPI OPENMP
OPTIONS_GROUP_PACKAGES=		AMRDATA EB LINEAR_SOLVERS PARTICLES SUNDIALS # TODO HYPRE PETSC HDF5

PARALLEL_DESC=			Enable parallelizations:
PACKAGES_DESC=			Enable packages:

OPTIONS_DEFINE=			PLOTFILE_TOOLS
OPTIONS_DEFAULT=		MPI OPENMP \
				AMRDATA EB LINEAR_SOLVERS PARTICLES \
				PLOTFILE_TOOLS
OPTIONS_SUB=			yes

MPI_CMAKE_ON=			AMReX_MPI
#MPI_USES=			mpi:openmpi # this fails with: The following options helpers are incorrectly set after bsd.port.options.mk and are ineffective: MPI_CFLAGS MPI_LIBS
MPI_CFLAGS=			`pkgconf --cflags ompi` # replacement
MPI_CXXFLAGS=			`pkgconf --cflags ompi` # replacement
MPI_LDFLAGS=			`pkgconf --libs ompi` # replacement
MPI_VARS=			MPIEXEC=${LOCALBASE}/mpi/openmpi/bin/mpiexec # replacement
MPI_LIB_DEPENDS=		libmpi_mpifh.so:net/openmpi # replacement
MPI_BINARY_ALIAS=		mpiexec=${MPIEXEC}

OPENMP_CMAKE_ON=		AMReX_OMP

AMRDATA_DESC=			Legacy plotfile data manipulation structures and formats
AMRDATA_CMAKE_BOOL=		AMReX_AMRDATA

EB_DESC=			Embedded Boundary cut-cell frameworks for complex/curved geometries
EB_CMAKE_BOOL=			AMReX_EB

LINEAR_SOLVERS_DESC=		Built-in, geometric multigrid (GMG) linear solvers
LINEAR_SOLVERS_CMAKE_BOOL=	AMReX_LINEAR_SOLVERS

PARTICLES_DESC=			Particle-in-Cell (PIC), cosmology, and tracer particle infrastructure
PARTICLES_CMAKE_BOOL=		AMReX_PARTICLES

SUNDIALS_DESC=			ODE/DAE SUNDIALS time-integrators
SUNDIALS_CMAKE_BOOL=		AMReX_SUNDIALS
SUNDIALS_LIB_DEPENDS=		libsundials_core.so:math/sundials
SUNDIALS_BROKEN=		all tests fail when SUNDIALS is enabled, see https://github.com/AMReX-Codes/amrex/issues/5528

PLOTFILE_TOOLS_DESC=		Enable Plotfile tools # project fails to build/indtall additional executables when this option is enabled
PLOTFILE_TOOLS_CMAKE_BOOL=	AMReX_PLOTFILE_TOOLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEB} && ${PORT_OPTIONS:MLINEAR_SOLVERS}
PLIST_FILES+=	include/AMReX_MLEBABecLap.H \
		include/AMReX_MLEBABecLap_3D_K.H \
		include/AMReX_MLEBABecLap_K.H \
		include/AMReX_MLEBTensorOp.H \
		include/AMReX_MLEBTensor_3D_K.H \
		include/AMReX_MLEBTensor_K.H
.endif

# tests as of 26.06: 100% tests passed, 0 tests failed out of 69

.include <bsd.port.mk>
