# $FreeBSD$

PORTNAME=	Flask-SocketIO
PORTVERSION=	2.9.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Socket.IO integration for Flask applications

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-engineio>=1.0.0:devel/py-python-engineio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-socketio>=1.5.0:devel/py-python-socketio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
