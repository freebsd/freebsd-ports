PORTNAME=	arviz-plots
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ready to use and composable plots for Bayesian Workflow
WWW=		https://python.arviz.org/projects/plots/en/latest/ \
		https://github.com/arviz-devs/arviz-plots

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arviz-base>=1.0.0:math/py-arviz-base@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arviz-stats>=1.0.0:math/py-arviz-stats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.9:math/py-matplotlib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5netcdf>0:science/py-h5netcdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

TEST_ARGS=	-p no:benchmark -p no:xdist -p no:relaxed \
		-W ignore::RuntimeWarning \
		--ignore=tests/test_plotly.py \
		--ignore=tests/test_backend.py
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		MPLBACKEND=Agg

PYTEST_IGNORED_TESTS=	bokeh plotly

# tests as of 1.0.0: 367 passed, 1 skipped, 276 deselected, 1 warning in 179.40s (0:02:59)

.include <bsd.port.mk>
