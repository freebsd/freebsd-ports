PORTNAME=	pytensor
DISTVERSION=	3.0.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimizing compiler for evaluating mathematical expressions
WWW=		https://pytensor.readthedocs.io/en/latest/ \
		https://github.com/pymc-devs/pytensor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioneer>=0.29:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cons>0:devel/py-cons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}etuples>0:devel/py-etuples@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.15:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logical-unification>0:math/py-logical-unification@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}miniKanren>0:devel/py-miniKanren@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.58:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # tests fail to run, see https://github.com/pymc-devs/pytensor/issues/355
TEST_ARGS=	tests/test_basic.py tests/test_config.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pytensor/scan/scan_perform${PYTHON_TAG}.so

# BUG: installs the file /usr/local/lib/python3.9/site-packages/bin/__init__.py, see https://github.com/pymc-devs/pytensor/issues/356

# BUG: sdist omits test helpers such as tests/unittest_tools.py and
# tests/graph/utils.py, so run only tests present in the distfile.

# tests as of 3.0.2: 19 passed in 7.33s

.include <bsd.port.mk>
