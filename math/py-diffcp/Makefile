PORTNAME=	diffcp
DISTVERSION=	1.1.9
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Differentiation through cone programs
WWW=		https://github.com/cvxgrp/diffcp/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=2.4:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scs>=3.0.0:math/py-scs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}threadpoolctl>=1.1:devel/py-threadpoolctl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clarabel>=0.5.1:math/py-clarabel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cvxpy>=1.6.3:math/py-cvxpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecos>=2.0.10:math/py-ecos@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++11-lang python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# test_clarabel.py::test_threading deadlocks in this environment.
PYTEST_IGNORED_TESTS=	test_threading

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/diffcp/_diffcp${PYTHON_TAG}.so

# tests as of 1.1.9: 41 passed, 2 deselected, 2 warnings in 5.68s

.include <bsd.port.mk>
