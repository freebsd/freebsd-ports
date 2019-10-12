# $FreeBSD$

PORTNAME=	nanoflann
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only library for Nearest Neighbor (NN) search with KD-trees

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	jlblancoc

CMAKE_OFF=	BUILD_EXAMPLES BUILD_TESTS

NO_ARCH=	yes

PLIST_FILES=	include/nanoflann.hpp \
		lib/cmake/nanoflann/nanoflannConfig.cmake \
		lib/cmake/nanoflann/nanoflannConfigVersion.cmake \
		lib/cmake/nanoflann/nanoflannTargets.cmake \
		libdata/pkgconfig/nanoflann.pc

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

benchmarks: build # benchmarks fail to run: https://github.com/jlblancoc/nanoflann/issues/100
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_BENCHMARKS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} benchmarks

.include <bsd.port.mk>
