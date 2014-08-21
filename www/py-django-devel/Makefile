# $FreeBSD$

PORTNAME=	django
PORTVERSION=	${SNAPSHOTDATE}
PORTEPOCH=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	Django-${SNAPSHOTDATE}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level Python Web framework

LICENSE=	BSD3CLAUSE

SNAPSHOTDATE=	20140821

USES=		cpe gettext
USE_GITHUB=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGVERSION=	1.7

GH_ACCOUNT=	${PORTNAME}
GH_TAGNAME=	ad96254
GH_COMMIT=	${GH_TAGNAME}

CONFLICTS=	py2[0-9]-django-[0-9]*
CPE_VENDOR=	djangoproject

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS_DEFINE=	FASTCGI HTMLDOCS
OPTIONS_DEFAULT=SQLITE
OPTIONS_GROUP=	DATABASE
OPTIONS_GROUP_DATABASE=	PGSQL MYSQL SQLITE
HTMLDOCS_DESC=	Install HTML documentation (requires Sphinx)

PLIST_FILES=	man/man1/django-admin.1.gz \
		man/man1/gather_profile_stats.1.gz

PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
FASTCGI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTMLDOCS}
.	if ! ${PORT_OPTIONS:MDOCS}
IGNORE=	you cannot build documentation with DOCS option disabled
.	endif
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
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
