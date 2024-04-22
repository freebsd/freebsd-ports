PORTNAME=	qats
DISTVERSION=	4.11.1
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient processing and visualization of time series
WWW=		https://github.com/dnvgl/qats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}QtPy>=1.9.0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}furo>=2022.12.7:textproc/py-furo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}myst-parser>=0.18.1:textproc/py-myst-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}npTDMS>=1.1.0:misc/py-npTDMS@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatreader>=0.0.24:misc/py-pymatreader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>=5.15.2:devel/pyside2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.2:science/py-scipy@${PY_FLAVOR}

USES=		pyqt:5 python
USE_PYTHON=	distutils concurrent autoplist pytest
USE_PYQT=	pyqt5

NO_ARCH=	yes

.include <bsd.port.mk>
