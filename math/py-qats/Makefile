PORTNAME=	qats
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.0
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient processing and visualization of time series
WWW=		https://github.com/dnvgl/qats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-dynamic-versioning>0:devel/py-poetry-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.5.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}npTDMS>=1.1.0:misc/py-npTDMS@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatreader>=0.0.24:misc/py-pymatreader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>=6.6:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.9.0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11.1:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	dnvgl

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy"

post-patch:
	@${REINPLACE_CMD} -e 's/version = "0.0.0"/version = "${DISTVERSION}"/' ${WRKSRC}/pyproject.toml

# tests as of 5.3.0: 121 passed in 10.81s

.include <bsd.port.mk>
