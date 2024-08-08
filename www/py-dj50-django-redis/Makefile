PORTNAME=	django-redis
PORTVERSION=	5.4.0
CATEGORIES=	www databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj50-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Full featured Redis cache/session backend for Django
WWW=		https://github.com/jazzband/django-redis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django50>=3.2:www/py-django50@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3:databases/py-redis@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-django>0:devel/py-pytest-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		redis-server:databases/redis

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent distutils pytest

TEST_ENV=	DJANGO_SETTINGS_MODULE=settings.sqlite \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
