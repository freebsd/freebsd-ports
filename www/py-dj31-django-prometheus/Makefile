PORTNAME=	django-prometheus
PORTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Export Django monitoring metrics for Prometheus.io

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.2:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-prometheus

NO_ARCH=		yes

OPTIONS_GROUP=		DATABASE CACHE
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL
OPTIONS_GROUP_CACHE=	MEMCACHED REDIS

MEMCACHED_DESC=		Memcached distributed memory caching support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:databases/py-python-memcached@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj31-django-redis>=4.8:www/py-dj31-django-redis@${PY_FLAVOR}

.include <bsd.port.mk>
