# $FreeBSD$

PORTNAME=	ALPSCore
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	science

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Generic algorithms and utilities for condensed matter physics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake:outsource
USE_GITHUB=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	test # 2 to 3 tests fail: https://github.com/ALPSCore/ALPSCore/issues/388

CMAKE_ARGS+=	-DDocumentation:BOOL=OFF # broken: https://github.com/ALPSCore/ALPSCore/issues/387
CMAKE_ARGS+=	-DTesting:BOOL=OFF # enable only for the 'test' target
CMAKE_ARGS_TEST=	-DTesting:BOOL=ON -DExtensiveTesting:BOOL=ON
CXXFLAGS+=	-DNDEBUG # see https://github.com/ALPSCore/ALPSCore/issues/389
LDFLAGS+=	-lexecinfo # https://github.com/ALPSCore/ALPSCore/issues/390

OPTIONS_DEFINE=	OPENMPI2
OPTIONS_DEFAULT=	OPENMPI2
OPENMPI2_DESC=	Parallel processing support via Open MPI 2.x

OPENMPI2_CMAKE_BOOL=	ENABLE_MPI
OPENMPI2_LIB_DEPENDS=	libmpi.so:net/openmpi2
OPENMPI2_VARS=		cc=${LOCALBASE}/mpi/openmpi2/bin/mpicc \
			cxx=${LOCALBASE}/mpi/openmpi2/bin/mpicxx

pre-test:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_ARGS_TEST} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

.include <bsd.port.mk>
