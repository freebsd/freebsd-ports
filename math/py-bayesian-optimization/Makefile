# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	bayesian-optimization
PORTVERSION=	1.2.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bayesian Optimization package

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.18.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.14.0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
