PORTNAME=	cvxpy
DISTVERSION=	1.3.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain-specific language for modeling convex optimization problems
WWW=		https://www.cvxpy.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ecos>=2:math/py-ecos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osqp>=0.4.1:math/py-osqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scs>=1.1.6:math/py-scs@${PY_FLAVOR}
TEST_DEPENDS=	pytest:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/cvxpy/cvxpy/issues/2174

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_cvxcore*.so

.include <bsd.port.mk>
