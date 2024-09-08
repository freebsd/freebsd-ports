PORTNAME=	nlcglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nonlinear CG methods for wave-function optimization in DFT
WWW=		https://github.com/simonpintarelli/nlcglib

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libkokkoscore.so:devel/kokkos \
		libopenblas.so:math/openblas
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	simonpintarelli

CMAKE_TESTING_ON=	BUILD_TESTS # tests fail to compile, see https://github.com/simonpintarelli/nlcglib/issues/19

OPTIONS_DEFINE=		OPENMP
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH OPENMP

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

OPENMP_CMAKE_BOOL=	USE_OPENMP # binaries are still linked with libomp when USE_OPENMP=OFF, see https://github.com/simonpintarelli/nlcglib/issues/13

.include <bsd.port.mk>
