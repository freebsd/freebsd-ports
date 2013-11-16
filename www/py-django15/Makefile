# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	django
PORTVERSION=	1.5.5
CATEGORIES=	www python
MASTER_SITES=	https://www.djangoproject.com/m/releases/${PORTVERSION:R}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level Python Web framework

LICENSE=	BSD

USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYTHON_PY3K_PLIST_HACK=	yes
PYDISTUTILS_PKGNAME=	Django

CONFLICTS=	py[23][0-9]-django-devel-[0-9]* py[23][0-9]-django-1.[0-46-9].*

DOCSDIR=	${PREFIX}/share/doc/py-django

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
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
.	if ! ${PORT_OPTIONS:MDOCS}
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
