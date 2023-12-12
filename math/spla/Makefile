PORTNAME=	spla
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Specialized Parallel Linear Algebra
WWW=		https://github.com/eth-cscs/spla

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas
TEST_DEPENDS=	scalapack>0:math/scalapack

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eth-cscs

CMAKE_TESTING_ON=	SPLA_BUILD_TESTS # tests fail to link, see https://github.com/eth-cscs/spla/issues/24
CMAKE_TESTING_ARGS=	-DFETCHCONTENT_FULLY_DISCONNECTED:BOOL=OFF # to allow to download google test
CMAKE_TESTING_TARGET=	${ALL_TARGET}

OPTIONS_DEFINE=		FORTRAN OPENMP
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	FORTRAN MPICH OPENMP
OPTIONS_SUB=		yes

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	SPLA_FORTRAN

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

OPENMP_CMAKE_BOOL=	SPLA_OMP

.include <bsd.port.mk>
