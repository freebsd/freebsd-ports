# New ports collection makefile for: roundup
# Date created:		23 Mar 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	roundup
PORTVERSION=	1.4.13
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sbrabez@gmail.com
COMMENT=	An Issue-Tracking System for Knowledge Workers

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GETTEXT=	yes

OPTIONS=	SQLITE	"Support Sqlite as backend" on
OPTIONS+=	PGSQL	"Support posggresql as backend" off
OPTIONS+=	MYSQL	"Support mysql as backend" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SQLITE)
.if ${PYTHON_REL} >= 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23
.endif
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		roundup-admin.1 roundup-demo.1 roundup-mailgw.1 \
		roundup-server.1
MANCOMPRESSED=	no
.endif

SCRIPTS=	roundup-admin roundup-demo roundup-gettext roundup-mailgw \
		roundup-server roundup-xmlrpc-server

post-install:
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/build/scripts-${PYTHON_VER}/,} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/share/man/man1/,} ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
