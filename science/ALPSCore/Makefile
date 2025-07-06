PORTNAME=	ALPSCore
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.2
CATEGORIES=	science

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Generic algorithms and utilities for condensed matter physics
WWW=		https://alpscore.org/ \
		https://github.com/ALPSCore/ALPSCore/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		cmake compiler:c++14-lang eigen:3
USE_CXXSTD=	c++14
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=		-DTesting:BOOL=OFF # enable only for the 'test' target
CMAKE_TESTING_ON=	Testing ExtensiveTesting

TEST_TARGET=	test # 2 to 3 tests fail: https://github.com/ALPSCore/ALPSCore/issues/388

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS DOXYGEN OPENMPI
OPTIONS_DEFAULT=	OPENMPI

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	Documentation

OPENMPI_LIB_DEPENDS=	libgcc_s.so:lang/gcc${GCC_DEFAULT} \
			libmpi_cxx.so:net/openmpi4
OPENMPI_CMAKE_BOOL=	ENABLE_MPI

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENMPI}
CC=	${LOCALBASE}/mpi/openmpi/bin/mpicc
CXX=	${LOCALBASE}/mpi/openmpi/bin/mpicxx
.endif

post-install-DOXYGEN-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/.tag

pre-test:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_ARGS_TEST} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

.include <bsd.port.post.mk>
