# $FreeBSD$

PORTNAME=	django
PORTVERSION=	${SNAPSHOTDATE}
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web framework

LICENSE=	BSD3CLAUSE

DEPRECATED=	Outdated version. Use www/py-django instead
EXPIRATION_DATE=2018-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${FLAVOR}

SNAPSHOTDATE=	20150709

NO_ARCH=	yes
USES=		cpe gettext python${PY_MYSQL} shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	django/bin/django-admin.py \
		django/conf/project_template/manage.py

GH_TAGNAME=	c954931

CONFLICTS=	py2[0-9]-django-[0-9]*
CPE_VENDOR=	djangoproject

DOCSDIR=	${PREFIX}/share/doc/py-django
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS FASTCGI HTMLDOCS
OPTIONS_DEFAULT=SQLITE
OPTIONS_GROUP=	DATABASE
OPTIONS_GROUP_DATABASE=	PGSQL MYSQL SQLITE
HTMLDOCS_DESC=	Install HTML documentation (requires Sphinx)

PLIST_FILES=	man/man1/django-admin.1.gz

HTMLDOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${FLAVOR}
HTMLDOCS_IMPLIES=	DOCS
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb@${FLAVOR}
MYSQL_VARS=	PY_MYSQL=:2.7
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}
FASTCGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup6>0:www/py-flup6@${FLAVOR}

post-build-HTMLDOCS-on:
	cd ${WRKSRC}/docs && ${MAKE} html SPHINXBUILD=sphinx-build-${PYTHON_VER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}/${MAN1PREFIX}/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""

post-install-HTMLDOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
