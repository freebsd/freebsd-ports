PORTNAME=	django-prometheus
DISTVERSION=	2.4.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_prometheus-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Export Django monitoring metrics for Prometheus.io
WWW=		https://github.com/django-commons/django-prometheus

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2<6.0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_GROUP=		DATABASE CACHE
OPTIONS_GROUP_CACHE=	MEMCACHED REDIS
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL

MEMCACHED_DESC=		Memcached distributed memory caching support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg>=0:databases/py-psycopg@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-redis>=4.12.1:www/py-django-redis@${PY_FLAVOR}

.include <bsd.port.mk>
