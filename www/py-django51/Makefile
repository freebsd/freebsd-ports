PORTNAME=	django
PORTVERSION=	5.1.12
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://media.djangoproject.com/releases/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	51
#DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python

PATCH_SITES=	https://github.com/django/django/commit/
PATCHFILES+=	8b9a2bf34e132ccf0ab0a074440dc55f90c76598.patch:-p1

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web Framework
WWW=		https://www.djangoproject.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.8.1:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.3.1:databases/py-sqlparse@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tblib>0:devel/py-tblib@${PY_FLAVOR}

USES=		cpe python:3.10+ shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-django
PLIST_FILES=	share/man/man1/django-admin.1.gz
PORTDOCS=	*

SHEBANG_FILES=	django/conf/project_template/manage.py-tpl

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django[0-9][0-9]

CPE_VENDOR=	djangoproject

# Upstream archive contains files with UTF-8 names
# EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

OPTIONS_DEFINE=	DOCS HTMLDOCS
OPTIONS_GROUP=	DATABASE
OPTIONS_GROUP_DATABASE=	PGSQL MYSQL SQLITE
OPTIONS_DEFAULT=SQLITE
HTMLDOCS_DESC=	Install HTML documentation (requires Sphinx)

HTMLDOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
HTMLDOCS_IMPLIES=	DOCS
HTMLDOCS_USES=		gmake
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.3.13:databases/py-mysqlclient@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

.include <bsd.port.pre.mk>

post-build-HTMLDOCS-on:
	cd ${WRKSRC}/docs && ${MAKE_CMD} html SPHINXBUILD=sphinx-build-${PYTHON_VER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}/${PREFIX}/share/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"	* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""

post-install-HTMLDOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${STAGEDIR}/${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} tests/runtests.py --settings=test_sqlite

.include <bsd.port.post.mk>
