PORTNAME=	flask-socketio
PORTVERSION=	5.6.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_socketio-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket.IO integration for Flask applications
WWW=		https://github.com/miguelgrinberg/Flask-SocketIO

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2.1.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-socketio>=5.12.0:devel/py-python-socketio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
