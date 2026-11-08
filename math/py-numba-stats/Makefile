PORTNAME=	numba-stats
PORTVERSION=	1.14.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numba-accelerated implementations of common probability distributions
WWW=		https://github.com/HDembinski/numba-stats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numba>=0.53:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydocstyle>=6:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=5.2.0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=5:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p benchmark -p pytest_cov

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD} # for tests

# tests as of 1.14.0: 903 passed in 94.24s (0:01:34)

.include <bsd.port.mk>
