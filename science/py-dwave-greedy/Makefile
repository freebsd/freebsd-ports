PORTNAME=	dwave-greedy
DISTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Greedy binary quadratic model solvers
WWW=		https://docs.ocean.dwavesys.com/projects/greedy/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dwave-samplers>=1.0.0:science/py-dwave-samplers@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dwave-system>=1.0.0:science/py-dwave-system@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c 'import ctypes, unittest; test_suite = unittest.defaultTestLoader.discover("."); test_result = unittest.TextTestRunner(verbosity=2).run(test_suite); raise SystemExit(not test_result.wasSuccessful())'

# tests as of 0.3.0: Ran 164 tests in 0.452s (OK)

.include <bsd.port.mk>
