PORTNAME=	arviz
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	math python
#MASTER_SITES=	PYPI # missing test files
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for exploratory analysis of Bayesian models
WWW=		https://python.arviz.org/en/stable/ \
		https://github.com/arviz-devs/arviz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arviz-base>=1.0.0:math/py-arviz-base@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arviz-stats>=1.0.0:math/py-arviz-stats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arviz-plots>=1.0.0:math/py-arviz-plots@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

TEST_ARGS=	-p no:benchmark -p no:xdist -p no:relaxed

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
