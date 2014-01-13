# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-cms
PORTVERSION=	2.4.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Content management system built with the Django framework

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>=0.7.3:${PORTSDIR}/databases/py-south \
		${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-classy-tags>=0.3.4.1:${PORTSDIR}/www/py-django-classy-tags \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.5.2:${PORTSDIR}/www/py-django-mptt \
		${PYTHON_PKGNAMEPREFIX}django-sekizai>=0.6.1:${PORTSDIR}/www/py-django-sekizai \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.90:${PORTSDIR}/www/py-html5lib

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_MULTI=	DATABASE
OPTIONS_DEFAULT=SQLITE
OPTIONS_MULTI_DATABASE=MYSQL PGSQL SQLITE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
