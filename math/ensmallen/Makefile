# $FreeBSD$

PORTNAME=	ensmallen
DISTVERSION=	2.11.5
CATEGORIES=	math
MASTER_SITES=	https://ensmallen.org/files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible C++ library for efficient mathematical optimization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/armadillo_bits/config.hpp:math/armadillo
RUN_DEPENDS=	${LOCALBASE}/include/armadillo_bits/config.hpp:math/armadillo

USES=		cmake localbase
CMAKE_OFF=	BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # tests are known to fail: https://github.com/mlpack/ensmallen/issues/142
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
