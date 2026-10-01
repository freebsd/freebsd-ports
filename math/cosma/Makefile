PORTNAME=	cosma
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.4
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed communication-optimal matrix multiplication algorithm
WWW=		https://github.com/eth-cscs/COSMA

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cxxopts>0:devel/cxxopts
LIB_DEPENDS=	libcosta.so:math/costa \
		libopenblas.so:math/openblas

USES=		cmake:testing mpi:mpich
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eth-cscs
GH_PROJECT=	COSMA
GH_TUPLE=	eth-cscs:Tiled-MM:9e880f9:tiledmm/libs/Tiled-MM

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	COSMA_WITH_TESTS
CMAKE_ARGS=	-DCOSMA_BLAS="OPENBLAS"
CMAKE_TESTING_ON=	COSMA_WITH_TESTS

LDFLAGS+=	-pthread

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

# tests as of 2.8.4: 100% tests passed, 0 tests failed out of 4

.include <bsd.port.mk>
