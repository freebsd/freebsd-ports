# $FreeBSD$

PORTNAME=	Flask-SocketIO
PORTVERSION=	2.9.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Socket.IO integration for Flask applications

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-engineio>=1.0.0:devel/py-python-engineio@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-socketio>=1.5.0:devel/py-python-socketio@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
