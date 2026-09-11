PORTNAME=	ensmallen
DISTVERSION=	3.11.1
CATEGORIES=	math
MASTER_SITES=	https://ensmallen.org/files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible C++ library for efficient mathematical optimization
WWW=		https://ensmallen.org \
		https://github.com/mlpack/ensmallen

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/armadillo_bits/config.hpp:math/armadillo
RUN_DEPENDS=	${LOCALBASE}/include/armadillo_bits/config.hpp:math/armadillo

USES=		cmake compiler:c++11-lang localbase
CMAKE_ON=	BUILD_TESTS # will be removed

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ensmallen_tests && \
		./ensmallen_tests

# tests as of 3.11.1: All tests passed (18640 assertions in 486 test cases)

.include <bsd.port.mk>
