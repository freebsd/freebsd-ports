PORTNAME=	django-cms
PORTVERSION=	5.0.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_cms-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Content management system built with the Django framework
WWW=		https://django-cms.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangocms-admin-style>=1.2:www/py-djangocms-admin-style@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-classy-tags>=0.7.2:www/py-django-classy-tags@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-formtools>=2.1:www/py-django-formtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-sekizai>=0.7:www/py-django-sekizai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-treebeard>=4.3:www/py-django-treebeard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>0:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

.include <bsd.port.mk>
