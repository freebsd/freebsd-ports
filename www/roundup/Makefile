# New ports collection makefile for: roundup
# Date created:		23 Mar 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	roundup
PORTVERSION=	1.4.2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	source/r/${PORTNAME}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	An Issue-Tracking System for Knowledge Workers

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
USE_GETTEXT=	yes

OPTIONS=	SQLITE	"Support Sqlite as backend" on
OPTIONS+=	PGSQL	"Support posggresql as backend" off
OPTIONS+=	MYSQL	"Support mysql as backend" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/sqlite/__init__.py:${PORTSDIR}/databases/py-PySQLite11
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

MAN1=		roundup-admin.1 roundup-demo.1 roundup-mailgw.1 \
		roundup-server.1

.include <bsd.port.post.mk>
