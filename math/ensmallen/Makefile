PORTNAME=	ensmallen
DISTVERSION=	3.11.2
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

# OpenBLAS dynamic architecture detection on AMD Zen 5 (and similar CPUs
# when AVX2/AVX512 kernels are disabled at build time) selects the Prescott
# SGEMM kernel, which crashes with a bus error during single-precision matrix
# multiplications.  Force a safe core type until OpenBLAS CPU detection handles
# this case correctly.
#TEST_ENV=	OPENBLAS_CORETYPE=SANDYBRIDGE # for Zen5 and similar

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_ARGS} ensmallen_tests && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} ./ensmallen_tests

# tests as of 3.11.2: All tests passed (18645 assertions in 487 test cases)

.include <bsd.port.mk>
