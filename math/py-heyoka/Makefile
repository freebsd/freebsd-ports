PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.0
PORTREVISION=	5
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library for ODE integration via Taylor's method and LLVM
WWW=		https://bluescarni.github.io/heyoka.py/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		${PYNUMPY}
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libgmp.so:math/gmp \
		libheyoka.so:math/heyoka \
		libmp++.so:math/mppp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libtbb.so:devel/onetbb \
		libspdlog.so:devel/spdlog
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang llvm:min=16,build,run python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni
GH_PROJECT=	${PORTNAME}.py

CMAKE_ON=	HEYOKA_PY_ENABLE_IPO
CMAKE_ARGS=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION:R} \
		-DPython3_EXECUTABLE=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	# testsuite based on instructions in https://bluescarni.github.io/heyoka.py/install.html#verifying-the-installation
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "import heyoka; heyoka.test.run_test_suite();"
	# integrate and plot an example
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example-restricted-three-body-problem.py

.include <bsd.port.mk>
