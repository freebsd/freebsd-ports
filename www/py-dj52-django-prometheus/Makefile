PORTNAME=	django-prometheus
DISTVERSION=	2.3.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Export Django monitoring metrics for Prometheus.io
WWW=		https://github.com/korfuri/django-prometheus

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=3.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_GROUP=		DATABASE CACHE
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL
OPTIONS_GROUP_CACHE=	MEMCACHED REDIS

MEMCACHED_DESC=		Memcached distributed memory caching support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj52-django-redis>=4.8:www/py-dj52-django-redis@${PY_FLAVOR}

.include <bsd.port.mk>
