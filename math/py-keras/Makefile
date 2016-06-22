# $FreeBSD$

PORTNAME=	keras
PORTVERSION=	1.0.4
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	neel@neelc.org
COMMENT=	Deep Learning library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}theano>=0.8.0:math/py-theano \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six \

USE_GITHUB=	yes
GH_ACCOUNT=	fchollet

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
