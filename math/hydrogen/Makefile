PORTNAME=	hydrogen
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.2
CATEGORIES=	math
PKGNAMESUFFIX=	-linear-algebra

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dense and sparse linear algebra, conic optimization, lattice reduction
WWW=		https://github.com/LLNL/Elemental

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cereal>0:devel/cereal
LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Elemental

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	Hydrogen_ENABLE_TESTING
CMAKE_TESTING_ON=	Hydrogen_ENABLE_TESTING # not clear how to run tests, see https://github.com/LLNL/Elemental/issues/156
CMAKE_TESTING_TARGET=

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFINE=		MPC
OPTIONS_DEFAULT=	MPICH # should be same as in misc/lbann

MPICH_USES=		mpi:mpich

MPC_DESC=		Use MPC(+MPFR+GMP) library and enable related features
MPC_CMAKE_BOOL=		Hydrogen_ENABLE_MPC
MPC_BROKEN=		fails to enable: Disabling MPFR since MPI_LONG_LONG was not detected

OPENMPI_USES=		mpi:openmpi

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
