PORTNAME=	hydrogen
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	math
PKGNAMESUFFIX=	-linear-algebra

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dense and sparse linear algebra, conic optimization, lattice reduction
WWW=		https://github.com/LLNL/Elemental

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cereal>0:devel/cereal \
		half>0:math/half
LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS=	half>0:math/half

USES=		cmake:testing compiler:c++17-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Elemental

CMAKE_ON=	BUILD_SHARED_LIBS \
		Hydrogen_ENABLE_HALF \
		Hydrogen_ENABLE_MPC \
		Hydrogen_ENABLE_QD
		#Hydrogen_ENABLE_ALUMINUM # depends on OpenMPI - so we disable it for now
CMAKE_OFF=	Hydrogen_ENABLE_TESTING
CMAKE_TESTING_ON=	Hydrogen_ENABLE_TESTING
CMAKE_TESTING_TARGET=	test

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # should be same as in misc/lbann

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
