# $FreeBSD$

PORTNAME=	keras
DISTVERSION=	2.3.1
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	neel@neelc.org
COMMENT=	Deep learning library for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.14:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}theano>=0.8.0:math/py-theano@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras-applications>=1.0.6:math/py-keras-applications@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keras-preprocessing>=1.0.5:math/py-keras-preprocessing@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	keras-team
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
SUB_FILES=	pkg-message

.include <bsd.port.mk>
