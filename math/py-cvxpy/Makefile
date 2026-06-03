PORTNAME=	cvxpy
DISTVERSION=	1.9.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain-specific language for modeling convex optimization problems
WWW=		https://www.cvxpy.org \
		https://github.com/cvxpy/cvxpy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clarabel>=0.5.0:math/py-clarabel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}highspy>=1.11.0:math/py-highspy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osqp>=1.0.0:math/py-osqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qdldl>=0.1.7.post0:math/py-qdldl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scs>=3.2.4.post1:math/py-scs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sparsediffpy>=0.3.0:math/py-sparsediffpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diffcp>0:math/py-diffcp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
		@${STRIP_CMD} \
			${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_cvxcore${PYTHON_TAG}.so

# tests as of 1.9.0: TBD

.include <bsd.port.mk>
