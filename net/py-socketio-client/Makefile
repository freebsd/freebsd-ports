# Created by: Massimiliano Stucchi <mstucchi@ripe.net>
# $FreeBSD$

PORTNAME=	socketio-client
PORTVERSION=	0.6.7
CATEGORIES=	net devel python
MASTER_SITES=	CHEESESHOP/source/s/socketIO-client/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	socketIO_client-${PORTVERSION}

MAINTAINER=	mstucchi@ripe.net
COMMENT=	Socket.io client library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.7:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
