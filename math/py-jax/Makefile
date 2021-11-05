# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	jax
PORTVERSION=	0.2.9
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Differentiate, compile, and transform Numpy code

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.12,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=0:math/py-opt-einsum@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
