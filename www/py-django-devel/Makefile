# $FreeBSD$

PORTNAME=	django
PORTVERSION=	${SNAPSHOTDATE}
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://people.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
MASTER_SITE_SUBDIR=	lwhsu/django
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	Django-${SNAPSHOTDATE}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level Python Web framework

LICENSE=	BSD

SNAPSHOTDATE=	20131025

USE_XZ=	yes
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYTHON_PY3K_PLIST_HACK=	yes
PYDISTUTILS_PKGNAME=	Django
PYDISTUTILS_PKGVERSION=	1.7

CONFLICTS=	py2[0-9]-django-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-django

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}-devel/options
OPTIONS_DEFINE=	FASTCGI HTMLDOCS
OPTIONS_DEFAULT=SQLITE
OPTIONS_GROUP=	DATABASE
OPTIONS_GROUP_DATABASE=	PGSQL MYSQL SQLITE
HTMLDOCS_DESC=	Install the HTML documentation (requires Sphinx)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MFASTCGI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup
.endif

.if ${PORT_OPTIONS:MHTMLDOCS}
.	if empty(PORT_OPTIONS:MDOCS)
IGNORE=	you cannot build documentation while setting NOPORTDOCS
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
