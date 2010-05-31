# New ports collection makefile for:	django-devel
# Date created:				Jul 04 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	django
PORTVERSION=	${REVISION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lwhsu/django
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	Django-r${REVISION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level Python Web framework

REVISION=	13124

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_PKGNAME=	Django
PYDISTUTILS_PKGVERSION=	1.2_rc_1

CONFLICTS=	py2[0-9]-django-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS=	MOD_PYTHON3	"Install Apache2 with mod_python3"	off \
		POSTGRESQL	"PostgreSQL support"	off \
		MYSQL	"MySQL support"	off \
		SQLITE	"SQLite support"	off \
		FASTCGI	"FastCGI support"	off \
		DOCS	"Install HTML documentation (requires Sphinx)"	off

MAN1=		daily_cleanup.1 django-admin.1 gather_profile_stats.1

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}-devel/options

.include <bsd.port.pre.mk>

.if defined(WITH_MOD_PYTHON3)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/mod_python/_psp.so:${PORTSDIR}/www/mod_python3
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_mysql.so:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_SQLITE)
.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif
.endif

.if defined(WITH_FASTCGI)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup
.endif

.if defined(WITH_DOCS)
.	if defined(NOPORTDOCS)
IGNORE=	you cannot build documentation while setting NOPORTDOCS
.	endif
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
PORTDOCS=	*
.endif

post-build:
.if defined(WITH_DOCS)
	cd ${WRKSRC}/docs && ${MAKE} html
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${MAN1PREFIX}/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""
.if defined(WITH_DOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
