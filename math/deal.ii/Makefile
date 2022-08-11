PORTNAME=	deal.II
DISTVERSIONPREFIX=	v
DISTVERSION=	9.4.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite element Differential Equations Analysis Library (DEAL)

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_FreeBSD_14=	clang crashes: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=257876
BROKEN_aarch64=		error: use of undeclared identifier '__TBB_machine_fetchadd4'

BUILD_DEPENDS=	${LOCALBASE}/include/boost/config.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libmetis.so:math/metis

USES=		blaslapack cmake:testing compiler:c++17-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl:S/.//}
GH_PROJECT=	${PORTNAME:tl:S/.//}

CMAKE_OFF=	DEAL_II_ALLOW_BUNDLED DEAL_II_COMPONENT_EXAMPLES \
		DEAL_II_WITH_P4EST DEAL_II_WITH_TRILINOS DEAL_II_WITH_UMFPACK \
		DEAL_II_WITH_NANOFLANN DEAL_II_WITH_MUPARSER DEAL_II_WITH_ASSIMP \
		DEAL_II_WITH_HDF5
CMAKE_ON=	DEAL_II_FORCE_BUNDLED_TBB # instead of LIB_DEPENDS+=libtbb.so:devel/onetbb, pending https://github.com/dealii/dealii/issues/11561
CMAKE_TESTING_ON=	FREEBSD_ENABLE_TESTS

OPTIONS_DEFINE=		ADOLC ARPACK GSL LAPACK MPI NETCDF OPENCASCADE PETSC SCALAPACK SUNDIALS
OPTIONS_DEFAULT=	GSL LAPACK # SUNDIALS

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

NETCDF_DESC=		Compile with Netcdf (only with MPI)
NETCDF_CMAKE_BOOL=	DEAL_II_WITH_NETCDF
NETCDF_CMAKE_ON=	-DNETCDF_INCLUDE_DIR:STRING=${LOCALBASE}/include -DNETCDF_CPLUSPLUS_LIBRARY:STRING=${LOCALBASE}/lib/libnetcdf_c++4.so
NETCDF_BROKEN=		see https://github.com/dealii/dealii/issues/7263

OPENCASCADE_DESC=	Compile with OpenCascade
OPENCASCADE_CMAKE_BOOL=	DEAL_II_WITH_OPENCASCADE
OPENCASCADE_CMAKE_ON=	-DOPENCASCADE_INCLUDE_DIR:STRING=${LOCALBASE}/include/OpenCASCADE
OPENCASCADE_LIB_DEPENDS=	libTKernel.so:cad/opencascade

PETSC_DESC=		Compile with Petsc (only with MPI)
PETSC_CMAKE_BOOL=	DEAL_II_WITH_PETSC
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_BROKEN=		see https://github.com/dealii/dealii/issues/7260

SCALAPACK_DESC=		Compile with ScaLAPACK (only with MPI)
SCALAPACK_CMAKE_BOOL=	DEAL_II_WITH_SCALAPACK
SCALAPACK_IMPLIES=	MPI LAPACK
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack

SUNDIALS_DESC=		Compile with SUNDIALS
SUNDIALS_CMAKE_BOOL=	DEAL_II_WITH_SUNDIALS
SUNDIALS_LIB_DEPENDS=	libsundials_arkode.so:math/sundials
SUNDIALS_BROKEN=	Build fails with: Required variable "SUNDIALS_LIB_PAR" set to NOTFOUND

post-patch: # unbundle boost
	@${RM} -r ${WRKSRC}/dealii/bundled/boost-*

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/*.log

.include <bsd.port.mk>
