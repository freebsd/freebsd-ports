PORTNAME=	Diofant
DISTVERSION=	0.13.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library for symbolic mathematics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isort>0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
# RUN_DEPENDS includes extra_reqs for convenience
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}gmpy2>=2.1.0b5:math/py-gmpy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>=0.19:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}theano>=0.9.0:math/py-theano@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist
NO_ARCH=	yes

pre-configure:
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py


.include <bsd.port.mk>
