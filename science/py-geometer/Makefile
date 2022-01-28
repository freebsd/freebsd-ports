# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	geometer
PORTVERSION=	0.3.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python geometry package based on projective geometry and numpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.15,1<1.23,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
