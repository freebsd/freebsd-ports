PORTNAME=	jax
PORTVERSION=	0.4.31
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Differentiate, compile, and transform Numpy code
WWW=		https://github.com/google/jax

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ml-dtypes>=0.2.0:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11.1:science/py-scipy@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
