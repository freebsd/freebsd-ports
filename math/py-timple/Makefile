PORTNAME=	timple
PORTVERSION=	0.1.5
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Extended functionality for plotting timedelta values with Matplotlib

LICENSE=	MIT

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

USES=	python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
