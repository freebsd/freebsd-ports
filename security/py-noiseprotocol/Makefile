PORTNAME=	noiseprotocol
PORTVERSION=	0.3.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python implementation of Noise Protocol Framework

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.8:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
