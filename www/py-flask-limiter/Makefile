PORTNAME=	Flask-Limiter
PORTVERSION=	3.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Flask-Limiter adds rate limiting to Flask applications
WWW=		https://github.com/alisaifee/flask-limiter

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.8:www/py-flask@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils concurrent

.include <bsd.port.mk>
