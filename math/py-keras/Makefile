PORTNAME=	keras
DISTVERSION=	3.12.0
CATEGORIES=	math python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-backend deep learning library for Python
WWW=		https://keras.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}absl-py>0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ml-dtypes>0:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}namex>0:devel/py-namex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}optree>0:devel/py-optree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tensorflow>=2.12.0:science/py-tensorflow@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR}

# Extra dependencies for optional backends (jax, torch)
# openvino backend not available as FreeBSD port
EXTRA_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>0:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
