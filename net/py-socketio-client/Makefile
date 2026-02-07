PORTNAME=	socketio-client
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	net devel python
MASTER_SITES=	PYPI/source/s/socketIO-client/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	socketIO_client-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Socket.io client library for Python
WWW=		https://github.com/invisibleroads/socketIO-client

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.7:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
