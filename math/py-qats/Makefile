PORTNAME=	qats
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.1
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient processing and visualization of time series
WWW=		https://github.com/dnvgl/qats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.11.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.7.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}npTDMS>=1.10.0:misc/py-npTDMS@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.0.3:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatreader>=0.0.32:misc/py-pymatreader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>=6.10.1:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.4.2:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10.1:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	dnvgl

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy"

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

# tests as of 5.4.1: 143 passed, 7 skipped, 61 subtests passed in 11.80s

.include <bsd.port.mk>
