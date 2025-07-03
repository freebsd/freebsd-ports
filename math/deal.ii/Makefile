PORTNAME=	deal.II
DISTVERSION=	9.6.2
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	https://github.com/dealii/dealii/releases/download/v${DISTVERSION}/
DISTNAME=	dealii-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite element Differential Equations Analysis Library (DEAL)
WWW=		https://www.dealii.org/ \
		https://github.com/dealii/dealii

LICENSE=	APACHE20 LGPL21
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.md
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.md

BROKEN_aarch64=		error: use of undeclared identifier '__TBB_machine_fetchadd4'
BROKEN_armv7=		clang runs out of memory
BROKEN_i386=		compilation fails: Kokkos assumes 64-bit build; i.e., 8-byte pointers

BUILD_DEPENDS=	${LOCALBASE}/include/boost/config.hpp:devel/boost-libs
LIB_DEPENDS=	libblis.so:math/blis \
		libboost_serialization.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libmetis.so:math/metis \
		libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
#		libkokkoscore.so:devel/kokkos TMP commented out for bundled kokkos, tests fail for non-bundled kokkos, see https://github.com/dealii/dealii/issues/15692

USES=		blaslapack cmake:testing compiler:c++17-lang localbase:ldflags xorg
USE_LDCONFIG=	yes

CMAKE_OFF=	DEAL_II_ALLOW_BUNDLED DEAL_II_COMPONENT_EXAMPLES \
		DEAL_II_WITH_P4EST DEAL_II_WITH_TRILINOS DEAL_II_WITH_UMFPACK \
		DEAL_II_WITH_NANOFLANN DEAL_II_WITH_MUPARSER DEAL_II_WITH_ASSIMP \
		DEAL_II_WITH_HDF5
CMAKE_ON=	DEAL_II_FORCE_BUNDLED_TBB # instead of LIB_DEPENDS+=libtbb.so:devel/onetbb, pending https://github.com/dealii/dealii/issues/11561
CMAKE_ON+=	FORCE_BUNDLED_KOKKOS # TMP turn on bundled kokkos
CMAKE_TESTING_ON=	FREEBSD_ENABLE_TESTS

LDFLAGS+=	-lomp
LDFLAGS+=	-lexecinfo # TMP for bundled kokkos

XARCH!=		uname -p

OPTIONS_DEFINE=		ADOLC ARPACK GSL LAPACK MPI OPENCASCADE PETSC SCALAPACK SLEPC SUNDIALS # for all options see contrib/docker/Dockerfile, TODO some of them need to be enabled here
OPTIONS_DEFAULT=	GSL LAPACK MPI OPENCASCADE PETSC SCALAPACK SLEPC SUNDIALS

ADOLC_DESC=		Compile with ADOL-C
ADOLC_CMAKE_BOOL=	DEAL_II_WITH_ADOLC
ADOLC_LIB_DEPENDS=	libadolc.so:math/adol-c
ADOLC_BROKEN=		requires the development version: see https://github.com/dealii/dealii/issues/7293

ARPACK_DESC=		Compile with Arpack and PArpack (only with MPI, LAPACK)
ARPACK_CMAKE_BOOL=	DEAL_II_WITH_ARPACK
ARPACK_CMAKE_ON=	-DARPACK_LINKER_FLAGS:STRING="${LDFLAGS}"
ARPACK_BUILD_DEPENDS=	arpack-ng>0:math/arpack-ng
ARPACK_RUN_DEPENDS=	arpack-ng>0:math/arpack-ng # itself doesn't link to arpack, but makes depending project link to it
ARPACK_IMPLIES=		LAPACK

GSL_DESC=		Compile with gsl
GSL_CMAKE_BOOL=		DEAL_II_WITH_GSL
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

LAPACK_DESC=		Compile with LAPACK for matrix operations
LAPACK_USES=		fortran
LAPACK_CMAKE_BOOL=	DEAL_II_WITH_LAPACK
LAPACK_CMAKE_ON=	-DLAPACK_LINKER_FLAGS:STRING="${LDFLAGS}"
LAPACK_LIB_DEPENDS=	libopenblas.so:math/openblas

MPI_DESC=		MPI support (math/sundials must be compiled with MPI)
MPI_USES=		fortran
MPI_CMAKE_BOOL=		DEAL_II_WITH_MPI
MPI_CMAKE_ON=		-DMPI_LINKER_FLAGS:STRING="${LDFLAGS}"
MPI_LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
			libmpich.so:net/mpich

OPENCASCADE_DESC=	Compile with OpenCascade
OPENCASCADE_CMAKE_BOOL=	DEAL_II_WITH_OPENCASCADE
OPENCASCADE_CMAKE_ON=	-DOPENCASCADE_INCLUDE_DIR:STRING=${LOCALBASE}/include/OpenCASCADE
OPENCASCADE_LIB_DEPENDS=	libTKernel.so:cad/opencascade

PETSC_DESC=		Compile with Petsc (only with MPI)
PETSC_USES=		xorg
PETSC_USE=		XORG=x11 # PETSc adds x11 through interface libraries
PETSC_CMAKE_BOOL=	DEAL_II_WITH_PETSC
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_IMPLIES=		MPI # has to use the same MPI as PETSc uses
.if ${XARCH:M*64*} # match index size width being set to 64 in science/PETSc and math/metis
PETSC_CMAKE_BOOL+=	DEAL_II_WITH_64BIT_INDICES # as opposed to 32-bit indices that are default in deal.II
.endif

SCALAPACK_DESC=		Compile with ScaLAPACK (only with MPI)
SCALAPACK_CMAKE_BOOL=	DEAL_II_WITH_SCALAPACK
SCALAPACK_IMPLIES=	MPI LAPACK
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack

SLEPC_DESC=		Compile with Slepc (only with MPI)
SLEPC_USES=		xorg
SLEPC_USE=		XORG=x11 # SLEPc adds x11 through interface libraries
SLEPC_CMAKE_BOOL=	DEAL_II_WITH_SLEPC
SLEPC_LIB_DEPENDS=	libslepc.so:math/slepc
SLEPC_IMPLIES=		MPI # has to use the same MPI as PETSc uses

SUNDIALS_DESC=		Compile with SUNDIALS
SUNDIALS_CMAKE_BOOL=	DEAL_II_WITH_SUNDIALS
SUNDIALS_LIB_DEPENDS=	libsundials_arkode.so:math/sundials

post-patch: # unbundle boost
	@${RM} -r ${WRKSRC}/dealii/bundled/boost-*

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/*.log

# the testsuite is excluded from the tarball: https://github.com/dealii/dealii/issues/17951

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
