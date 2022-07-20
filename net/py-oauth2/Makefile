PORTNAME=	oauth2
DISTVERSION=	1.9.0.post1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for OAuth version 1.0

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>
