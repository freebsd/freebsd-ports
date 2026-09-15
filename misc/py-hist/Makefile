PORTNAME=	hist
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	misc python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Histogramming for analysis powered by boost-histogram
WWW=		https://hist.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-histogram>=1.7:misc/py-boost-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}histoprint>=2.2.0:misc/py-histoprint@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awkward>=2.0.7:math/py-awkward@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2022:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask-histogram>=2023.1:devel/py-dask-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.10.7:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mplhep>=0.3.33:science/py-mplhep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mpl>=0.12:devel/py-pytest-mpl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	scikit-hep

NO_ARCH=	yes

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}
TEST_ARGS=	--disable-plugin-autoload -p pytest_mpl \
		--ignore=tests/test_chunked.py \
		--ignore=tests/test_dask.py \
		--ignore=tests/test_plot.py \
		--ignore=tests/test_plot1.py \
		--ignore=tests/test_plot2.py

BINARY_ALIAS=	git=false

# tests as of 2.11.0: 178 passed in 20.33s

.include <bsd.port.mk>
