# New ports collection makefile for:	django
# Date created:				2005-11-19
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	django
PORTVERSION=	1.1.2
CATEGORIES=	www python
MASTER_SITES=	http://media.djangoproject.com/releases/${PORTVERSION}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level Python Web framework

LATEST_LINK=	${PYTHON_PKGNAMEPREFIX}django11

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Django

CONFLICTS=	py2[0-9]-django-devel-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS=	MOD_PYTHON3	"Install Apache2 with mod_python3"	off \
		POSTGRESQL	"PostgreSQL support"	off \
		MYSQL	"MySQL support"	off \
		SQLITE	"SQLite support"	off \
		FASTCGI	"FastCGI support"	off \
		DOCS	"Install HTML documentation (requires Sphinx)"	off

MAN1=		daily_cleanup.1 django-admin.1 gather_profile_stats.1

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

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
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
PORTDOCS=	*
.endif

post-build:
.if defined(WITH_DOCS)
.	if defined(NOPORTDOCS)
IGNORE=	you cannot build documentation while setting NOPORTDOCS
.	endif
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
