# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	django
PORTVERSION=	1.8.10
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		https://www.djangoproject.com/m/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	18
DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web Framework (1.8.x LTS)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	py??-django-devel-* py??-django-1.[012345679].*
CPE_VENDOR=		djangoproject

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS_DEFINE=		FASTCGI HTMLDOCS
OPTIONS_DEFAULT=	SQLITE

OPTIONS_GROUP=		DATABASE
OPTIONS_GROUP_DATABASE=	PGSQL MYSQL SQLITE

HTMLDOCS_DESC=	Install HTML documentation (requires Sphinx)

PLIST_FILES=	man/man1/django-admin.1.gz

PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
FASTCGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup>0:www/py-flup

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTMLDOCS}
.	if empty(PORT_OPTIONS:MDOCS)
IGNORE=	you cannot build documentation with DOCS option disabled
.	endif
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx
PORTDOCS=	*
.endif

post-build:
.if ${PORT_OPTIONS:MHTMLDOCS}
	cd ${WRKSRC}/docs && ${MAKE} html
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}/${MAN1PREFIX}/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.mk>
