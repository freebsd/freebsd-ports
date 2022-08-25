PORTNAME=	mfem
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight, general, scalable C++ library for finite element methods

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	MFEM_ENABLE_TESTING # tests are broken, see https://github.com/mfem/mfem/issues/3163

OPTIONS_DEFINE=		SUPERLU
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # should be the same choice as in science/hypre
OPTIONS_SUB=		yes

NOMPI_DESC=		Build without parallel processing support
OPENMPI_CMAKE_ON=	-DTPL_ENABLE_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DTPL_ENABLE_MPI=ON
MPICH_LIB_DEPENDS=	libHYPRE.so:science/hypre \
			libmetis.so:math/metis

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DTPL_ENABLE_MPI=ON
OPENMPI_LIB_DEPENDS=	libHYPRE.so:science/hypre \
			libmetis.so:math/metis

SUPERLU_DESC=		Enable SuperLU use
SUPERLU_CMAKE_BOOL=	MFEM_USE_SUPERLU
SUPERLU_CMAKE_ON=	-DSuperLUDist_DIR=${LOCALBASE} -DSuperLUDist_INCLUDE_DIRS=${LOCALBASE}/include/superlu
SUPERLU_BROKEN=		build fails, see https://github.com/mfem/mfem/issues/3171

.include <bsd.port.mk>
