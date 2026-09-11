PORTNAME=	arviz-plots
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ready to use and composable plots for Bayesian Workflow
WWW=		https://python.arviz.org/projects/plots/en/latest/ \
		https://github.com/arviz-devs/arviz-plots

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arviz-base>=1.3.0:math/py-arviz-base@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arviz-stats>=1.3.0:math/py-arviz-stats@${PY_FLAVOR}
		# www/py-bokeh should also be added, however it is broken because it is only for numpy-1.x
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5netcdf>0:science/py-h5netcdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.9:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

TEST_ARGS=	-p no:benchmark -p no:xdist -p no:relaxed \
		-p no:black -p no:ruff -p no:mypy -p no:flake8 -p no:cov \
		-W ignore::RuntimeWarning \
		-W ignore::DeprecationWarning \
		--ignore=tests/test_backend.py \
		--ignore=tests/test_plotly.py \
		--ignore=tests/test_styles.py
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		MPLBACKEND=Agg

# tests as of 1.3.1: 601 passed 163 failed, all failures are due to broken old version of www/py-bokeh which is still for numpy-1.x, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=295711

.include <bsd.port.mk>
