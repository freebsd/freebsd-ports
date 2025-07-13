PORTNAME=	django-tasks
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_tasks-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation and backport of background workers and tasks in Django
WWW=		https://github.com/RealOrangeOne/django-tasks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-stubs-ext>=0:www/py-django-stubs-ext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	MYSQL POSTGRES RQ
POSTGRES_DESC=	PostgreSQL database support
RQ_DESC=	RQ (Redis Queue) support

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR}
POSTGRES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg>=0:databases/py-psycopg@${PY_FLAVOR}
RQ_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}django-rq>=0:devel/py-django-rq@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rq-scheduler>=0:devel/py-rq-scheduler@${PY_FLAVOR}

.include <bsd.port.mk>
