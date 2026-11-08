PORTNAME=	dwavebinarycsp
DISTVERSION=	0.3.1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Map CSP with binary variables to binary quadratic models
WWW=		https://docs.ocean.dwavesys.com/projects/binarycsp/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.10.9:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.4:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}penaltymodel>=1.0.0:science/py-penaltymodel@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c 'import ctypes, unittest; test_suite = unittest.defaultTestLoader.discover("tests"); test_result = unittest.TextTestRunner(verbosity=2).run(test_suite); raise SystemExit(not test_result.wasSuccessful())'

# tests as of 0.3.1: Ran 51 tests in 16.175s (OK)

.include <bsd.port.mk>
