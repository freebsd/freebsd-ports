PORTNAME=	eemeter
DISTVERSION=	4.1.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package implementing methods to calculate metered energy consumption
WWW=		https://eemeter.openee.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fdasrsf>=2.4.1:math/py-fdasrsf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nlopt>0:math/py-nlopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pywavelets>0:math/py-pywavelets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-fda>0:math/py-scikit-fda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.3.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>0:math/py-statsmodels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # several tests fail, see https://github.com/openeemeter/eemeter/issues/508

TEST_ENV=	${MAKE_ENV} PYTEST_ADDOPTS="-p no:xdist -p no:benchmark -p no:cov -p no:black -p no:ruff -p no:flake8 -p no:mypy -o filterwarnings=ignore::pydantic.warnings.PydanticDeprecatedSince211"

# tests as of 4.1.1: 289 passed, 1 failed, 30 errors. The failure is a missing
# tests/legacy_hourly.json file in the sdist; the errors are missing 'snapshot'
# fixtures used by upstream snapshot tests.

.include <bsd.port.mk>
