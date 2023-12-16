PORTNAME=	Flask-Sockets
PORTVERSION=	0.2.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Elegant WebSockets for your Flask apps
WWW=		https://github.com/kennethreitz/flask-sockets

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
