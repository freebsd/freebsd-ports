PORTNAME=	neo
PORTVERSION=	0.14.5
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for representing electrophysiology data in Python
WWW=		https://neo.readthedocs.io/en/latest/ \
		https://github.com/NeuralEnsemble/python-neo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.16.4:science/py-quantities@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coveralls>=0:devel/py-coveralls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}datalad>=0:sysutils/py-datalad@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}igor2>=0:science/py-igor2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.0.0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}klusta>=0:science/py-klusta@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nixio>=0:science/py-nixio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}probeinterface>=0:science/py-probeinterface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyEDFlib>=0:misc/py-pyEDFlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynwb>=0:science/py-pynwb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wenv>=0:devel/py-wenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zugbruecke>=0.2:devel/py-zugbruecke@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		DISPLAY=${DISPLAY} \
		XAUTHORITY=${XAUTHORITY}
TEST_WRKSRC=	${WRKSRC}/neo/test

NO_ARCH=	yes

# tests as of 0.14.4: 1 failed, 675 passed, 737 skipped, 1 warning in 11.78s

.include <bsd.port.mk>
