# $FreeBSD$

PORTNAME=	deal.II
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.0
PORTREVISION=	1
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite element Differential Equations Analysis Library (DEAL)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libmetis.so:math/metis \
		libsundials_arkode.so:math/sundials \
		libtbb.so:devel/tbb

USES=		cmake:outsource compiler:c++17-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl:S/.//}
GH_PROJECT=	${PORTNAME:tl:S/.//}
USE_LDCONFIG=	yes

CMAKE_OFF=	DEAL_II_ALLOW_BUNDLED DEAL_II_COMPONENT_EXAMPLES \
		DEAL_II_WITH_P4EST DEAL_II_WITH_TRILINOS DEAL_II_WITH_UMFPACK DEAL_II_WITH_SLEPC \
		DEAL_II_WITH_NANOFLANN DEAL_II_WITH_MUPARSER DEAL_II_WITH_ASSIMP DEAL_II_WITH_ARPACK \
		DEAL_II_WITH_ADOLC DEAL_II_WITH_SUNDIALS DEAL_II_WITH_HDF5

OPTIONS_DEFINE=		LAPACK MPI NETCDF OPENCASCADE PETSC SCALAPACK
OPTIONS_DEFAULT=	MPI

LAPACK_DESC=		Build with LAPACK for matrix operations
LAPACK_USES=		fortran
LAPACK_CMAKE_BOOL=	DEAL_II_WITH_LAPACK
LAPACK_LIB_DEPENDS=	libblas.so:math/blas \
			liblapack.so:math/lapack
LAPACK_BROKEN=		can't find lapack library

MPI_USES=		fortran
MPI_CMAKE_BOOL=		DEAL_II_WITH_MPI
MPI_LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
			libmpi.so:net/openmpi

NETCDF_DESC=		Compile with Netcdf (only with MPI)
NETCDF_CMAKE_BOOL=	DEAL_II_WITH_NETCDF
NETCDF_CMAKE_ON=	-DNETCDF_INCLUDE_DIR:STRING=${LOCALBASE}/include -DNETCDF_CPLUSPLUS_LIBRARY:STRING=${LOCALBASE}/lib/libnetcdf_c++4.so
NETCDF_BROKEN=		see https://github.com/dealii/dealii/issues/7263

OPENCASCADE_DESC=	Build with OpenCascade
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

.include <bsd.port.mk>
