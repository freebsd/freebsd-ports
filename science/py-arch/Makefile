PORTNAME=	arch
DISTVERSION=	9.0.0
CATEGORIES=	science finance python # economics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Autoregressive Conditional Heteroskedasticity (ARCH) models
WWW=		https://github.com/bashtage/arch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.18.0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=9.2.0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.22.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.4.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.8:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.13.1:math/py-statsmodels@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>0:math/py-seaborn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_WRKSRC=	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/arch/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		MPLBACKEND=Agg OMP_NUM_THREADS=1
# The covariance and unitroot suites are ignored because they take over an hour
# test_runner and test_extra_args are deselected because they run arch.test() with an unregistered 'gpu' marker
TEST_ARGS=	-p xdist -n ${MAKE_JOBS_NUMBER} --ignore=covariance --ignore=unitroot \
		-k "not test_runner and not test_extra_args"

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/bootstrap/_samplers${PYTHON_SOABI}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/univariate/recursions${PYTHON_SOABI}.so

# tests as of 9.0.0: 20517 passed, 17 skipped in 96.45s (covariance and unitroot ignored)

.include <bsd.port.mk>
