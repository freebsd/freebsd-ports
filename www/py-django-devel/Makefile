# New ports collection makefile for:	django-devel
# Date created:				Jul 04 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

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

SNAPSHOTDATE=	20120731

USE_XZ=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_PKGNAME=	Django
PYDISTUTILS_PKGVERSION=	1.5

CONFLICTS=	py2[0-9]-django-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS_DEFINE=	PGSQL MYSQL SQLITE FASTCGI DOCS
OPTIONS_DEFAULT=

HTMLDOCS_DESC=	Build and install the HTML documentation (requires Sphinx)

MAN1=		daily_cleanup.1 django-admin.1 gather_profile_stats.1

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}-devel/options

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/_psycopg.so:${PORTSDIR}/databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MFASTCGI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup
.endif

.if ${PORT_OPTIONS:MHTMLDOCS}
.	if defined(NOPORTDOCS)
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
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${MAN1PREFIX}/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
