PORTNAME=	nanoflann
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for Nearest Neighbor (NN) search with KD-trees
WWW=		https://github.com/jlblancoc/nanoflann

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	jlblancoc

CMAKE_OFF=	NANOFLANN_BUILD_EXAMPLES NANOFLANN_BUILD_TESTS

NO_ARCH=	yes

PLIST_FILES=	include/nanoflann.hpp \
		libdata/pkgconfig/nanoflann.pc \
		share/cmake/nanoflann/nanoflannConfig.cmake \
		share/cmake/nanoflann/nanoflannConfigVersion.cmake \
		share/cmake/nanoflann/nanoflannTargets.cmake

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNANOFLANN_BUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

benchmarks: build # benchmarks fail to run: https://github.com/jlblancoc/nanoflann/issues/100
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_BENCHMARKS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} benchmarks

.include <bsd.port.mk>
