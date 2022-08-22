PORTNAME=	mfem
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4
PORTREVISION=	2
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

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # should be the same choice as in science/hypre

NOMPI_DESC=		Build without parallel processing support
NOMPI_CMAKE_ON=		-DMFEM_USE_MPI=OFF

MPICH_CMAKE_ON=		-DMFEM_USE_MPI=ON \
			-DMPI_HOME=${LOCALBASE}
MPICH_BUILD_DEPENDS=	mpich>0:net/mpich
MPICH_LIB_DEPENDS=	libHYPRE.so:science/hypre \
			libmetis.so:math/metis
MPICH_RUN_DEPENDS=	mpich>0:net/mpich

OPENMPI_CMAKE_ON=	-DMFEM_USE_MPI=ON \
			-DMPI_HOME=${LOCALBASE}/mpi/openmpi
OPENMPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_LIB_DEPENDS=	libHYPRE.so:science/hypre \
			libmetis.so:math/metis
OPENMPI_RUN_DEPENDS=	openmpi>0:net/openmpi

.include <bsd.port.mk>
