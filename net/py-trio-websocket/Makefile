PORTNAME=	trio-websocket
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WebSocket library for Trio
WWW=		https://github.com/python-trio/trio-websocket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.11:net/py-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=0.14:net/py-wsproto@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
