# $FreeBSD$

PORTNAME=	ALPSCore
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	12
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic algorithms and utilities for condensed matter physics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BROKEN_i386=	fails to build: no matching member function for call to 'read'

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		cmake compiler:c++11-lang eigen:3
USE_GITHUB=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	test # 2 to 3 tests fail: https://github.com/ALPSCore/ALPSCore/issues/388

CMAKE_ARGS+=	-DTesting:BOOL=OFF # enable only for the 'test' target
CMAKE_ARGS_TEST=	-DTesting:BOOL=ON -DExtensiveTesting:BOOL=ON
CXXFLAGS+=	-DNDEBUG # see https://github.com/ALPSCore/ALPSCore/issues/389
LDFLAGS+=	-lexecinfo # https://github.com/ALPSCore/ALPSCore/issues/390

OPTIONS_DEFINE=	DOXYGEN DOCS OPENMPI
OPTIONS_DEFAULT=	OPENMPI
OPENMPI_DESC=	Parallel processing support via Open MPI 3.x

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_CMAKE_BOOL=	Documentation
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

OPENMPI_CMAKE_BOOL=	ENABLE_MPI
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi

PORTDOCS=	*

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
