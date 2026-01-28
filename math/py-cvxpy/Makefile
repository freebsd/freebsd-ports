PORTNAME=	cvxpy
DISTVERSION=	1.6.4
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain-specific language for modeling convex optimization problems
WWW=		https://www.cvxpy.org \
		https://github.com/cvxpy/cvxpy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ecos>=2:math/py-ecos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}clarabel>=0.5.0:math/py-clarabel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daqp>0:math/py-daqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osqp>0:math/py-osqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PySCIPOpt>0:math/py-PySCIPOpt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scs>0:math/py-scs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diffcp>0:math/py-diffcp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
		@${STRIP_CMD} \
			${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_cvxcore${PYTHON_TAG}.so \
			${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_cvxpy_sparsecholesky${PYTHON_TAG}.so

# tests as of 1.6.4: 4 failed, 1308 passed, 216 skipped, 534 warnings in 610.43s (0:10:10)

.include <bsd.port.mk>
