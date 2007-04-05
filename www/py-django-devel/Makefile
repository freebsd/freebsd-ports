# New ports collection makefile for:	django-devel
# Date created:				Jul 04 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	django-devel
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	www python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lwhsu/django
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python
SNAPSHOT=	20070404

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web framework

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

CONFLICTS=	py2[0-9]-django-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS=	MOD_PYTHON3	"Install Apache2 with mod_python3"	off \
		POSTGRESQL	"PostgreSQL support"	off \
		MYSQL	"MySQL support"	off \
		SQLITE	"SQLite support"	off \
		FASTCGI	"FastCGI support"	off

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
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20
.endif

.if defined(WITH_FASTCGI)
PYFLUP_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-flup/Makefile -V PYFLUP_EGG
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/${PYFLUP_EGG}/flup/__init__.py:${PORTSDIR}/www/py-flup
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See ${DOCSDIR} for complete documentation"
	@${ECHO_MSG}	""
.else
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See http://www.djangoproject.com/documentation/ for complete documentation"
	@${ECHO_MSG}	""
.endif

.include <bsd.port.post.mk>
