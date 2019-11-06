# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	django
PORTVERSION=	2.1.14
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		https://www.djangoproject.com/m/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	21
DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web Framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python:3.5+ shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	django/bin/django-admin.py \
		django/conf/project_template/manage.py-tpl

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django111 ${PYTHON_PKGNAMEPREFIX}django22
CPE_VENDOR=		djangoproject

DOCSDIR=		${PREFIX}/share/doc/py-django
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS HTMLDOCS
OPTIONS_DEFAULT=	SQLITE

OPTIONS_GROUP=		DATABASE
OPTIONS_GROUP_DATABASE=	PGSQL MYSQL SQLITE

HTMLDOCS_DESC=		Install HTML documentation (requires Sphinx)

PLIST_FILES=		man/man1/django-admin.1.gz

HTMLDOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
HTMLDOCS_IMPLIES=	DOCS
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb@${PY_FLAVOR}
MYSQL_BROKEN=		MySQLdb only supports Python 2.
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

post-build-HTMLDOCS-on:
	cd ${WRKSRC}/docs && ${MAKE} html SPHINXBUILD=sphinx-build-${PYTHON_VER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}/${MAN1PREFIX}/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"	* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""

post-install-HTMLDOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
