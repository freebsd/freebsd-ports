PORTNAME=	cosma
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed communication-optimal matrix multiplication algorithm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	openmpi>0:net/openmpi
LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eth-cscs
GH_PROJECT=	COSMA
GH_TUPLE=	eth-cscs:COSTA:e48f571:costa/libs/COSTA \
		eth-cscs:Tiled-MM:9e880f9:tiledmm/libs/Tiled-MM

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	COSMA_WITH_TESTS
CMAKE_ARGS=	-DCOSMA_BLAS="OPENBLAS"
CMAKE_TESTING_ON=	COSMA_WITH_TESTS

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} \
			include/costa/pxtran \
			include/costa/pxtranc \
			include/costa/pxtranu

.include <bsd.port.mk>
