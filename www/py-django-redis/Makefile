PORTNAME=	django-redis
PORTVERSION=	5.4.0
CATEGORIES=	www databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full featured Redis cache/session backend for Django
WWW=		https://github.com/jazzband/django-redis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.0.0:databases/py-redis@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-django>=0:devel/py-pytest-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

# Required for Python 3.11+ as the cgi module is deprecated and slated for removal in Python 3.13
TEST_ARGS=	-W ignore::DeprecationWarning
TEST_ENV=	DJANGO_SETTINGS_MODULE=settings.sqlite \
		PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*django-redis

.include <bsd.port.mk>
