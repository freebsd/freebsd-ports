PORTNAME=	numdifftools
DISTVERSION=	0.9.42
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for automatic numerical differentiation problems
WWW=		https://github.com/pbrod/numdifftools/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.3:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=3.6:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.6:math/py-statsmodels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} MPLBACKEND=Agg PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
PYTEST_ARGS=	--override-ini=addopts= src/numdifftools/tests/

# tests as of 0.9.42: 116 passed, 28 skipped, 242 warnings in 12.80s

.include <bsd.port.mk>
