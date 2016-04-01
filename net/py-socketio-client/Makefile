# Created by: Massimiliano Stucchi <mstucchi@ripe.net>
# $FreeBSD$

PORTNAME=	socketio-client
PORTVERSION=	0.6.5
CATEGORIES=	net devel python
MASTER_SITES=	CHEESESHOP/source/s/socketIO-client/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	socketIO_client-${PORTVERSION}

MAINTAINER=	mstucchi@ripe.net
COMMENT=	Socket.io client library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
