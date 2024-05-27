PORTNAME=	django-prometheus
PORTVERSION=	2.3.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Export Django monitoring metrics for Prometheus.io
WWW=		https://github.com/korfuri/django-prometheus

LICENSE=	APACHE20

DEPRECATED=	Obsolete, please use www/py-django-prometheus instead
EXPIRATION_DATE=2024-06-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_GROUP=		DATABASE CACHE
OPTIONS_GROUP_CACHE=	MEMCACHED REDIS
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL

MEMCACHED_DESC=		Memcached distributed memory caching support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj42-django-redis>=4.8:www/py-dj42-django-redis@${PY_FLAVOR}

.include <bsd.port.mk>
