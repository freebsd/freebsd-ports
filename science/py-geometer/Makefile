# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	geometer
PORTVERSION=	0.2.3
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python geometry package based on projective geometry and numpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.15,1<1.20,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.3:math/py-sympy@${PY_FLAVOR} # <= 1.7

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
