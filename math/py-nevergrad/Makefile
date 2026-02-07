PORTNAME=	nevergrad
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python toolbox for performing gradient-free optimization
WWW=		https://facebookresearch.github.io/nevergrad/ \
		https://github.com/facebookresearch/nevergrad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bayesian-optimization>=1.2.0:math/py-bayesian-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cma>=2.6.0:math/py-cma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.6:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
