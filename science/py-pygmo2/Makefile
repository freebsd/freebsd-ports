PORTNAME=	pygmo2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20.0
CATEGORIES=	science graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python platform to perform parallel computations of optimisation tasks
WWW=		https://esa.github.io/pygmo2/ \
		https://github.com/esa/pygmo2

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libpagmo.so:science/pagmo2 \
		libboost_serialization.so:devel/boost-libs \
		libnlopt.so:math/nlopt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>0:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	esa

CMAKE_ON=	PYGMO_ENABLE_IPO
CMAKE_ARGS=	-DFREEBSD_PYTHON_DISTVERSION=${PYTHON_DISTVERSION}

CXXFLAGS+=	-I${LOCALBASE}/include/coin # see https://github.com/esa/pygmo2/issues/58

#TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test: # tests require sysctl sudo sysctl kern.threads.max_threads_per_proc variable to be at least 15000 ; test taken from azure-pipelines.yml
	# some tests fail, see https://github.com/esa/pygmo2/issues/135
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "import pygmo; pygmo.test.run_test_suite(1); pygmo.mp_island.shutdown_pool(); pygmo.mp_bfe.shutdown_pool()"

# tests as of 2.20.0: Ran 72 tests in 28.615s

.include <bsd.port.mk>
