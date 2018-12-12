# $FreeBSD$

PORTNAME=	Diofant
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library for symbolic mathematics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isort>0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
# RUN_DEPENDS includes extra_reqs for convenience
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gmpy2>=2.0.8:math/py-gmpy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>2.1.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>=0.19:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>2.1.2:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strategies>=0.2.3:devel/py-strategies@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}theano>=0.9.0:math/py-theano@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
