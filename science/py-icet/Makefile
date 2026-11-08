PORTNAME=	icet
DISTVERSION=	4.0
CATEGORIES=	science # chemistry, physics
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythonic approach to alloy cluster expansions
WWW=		https://icet.materialsmodeling.org \
		https://gitlab.com/materials-modeling/icet

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=3.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.59:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.5:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trainstation>=1.1:science/py-trainstation@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	pep517 autoplist pytest

USE_GITLAB=	yes
GL_ACCOUNT=	materials-modeling

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
PYTEST_IGNORED_TESTS=	test_run_forward \
			test_structure_enumeration_matches_reference

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -maxdepth 1 -name '_icet*.so' -exec ${STRIP_CMD} {} +

pre-test: # this test causes the whole testsuite to hard-fail in the beginning for some reason
	@${RM} -rf ${TEST_WRKSRC}/unittest/test_mchammer/test_site_occupancy_observer.py

# tests as of 4.0: 1569 passed, 1 skipped, 2 deselected, 5 warnings, 265 subtests passed in 166.32s (0:02:46)

.include <bsd.port.mk>
