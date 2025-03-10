PORTNAME=	hist
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-histogram>=1.3.1:misc/py-boost-histogram@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}histoprint>=2.2.0:misc/py-histoprint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>=2022:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask-histogram>=2023.1:devel/py-dask-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mplhep>0:science/py-mplhep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mpl>=0.12:devel/py-pytest-mpl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 21 tests fail: _tkinter.TclError: no display name and no $DISPLAY environment variable

USE_GITHUB=	yes
GH_ACCOUNT=	scikit-hep

NO_ARCH=	yes

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
