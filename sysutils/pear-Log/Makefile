# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.9.11
PORTREVISION=	1
CATEGORIES=	sysutils www pear

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

FILES=		Log/composite.php Log/console.php Log/daemon.php \
		Log/display.php Log/error_log.php Log/file.php \
		Log/firebug.php Log/mail.php Log/mcal.php Log/mdb2.php \
		Log/null.php Log/observer.php Log/sql.php Log/sqlite.php \
		Log/syslog.php Log/win.php Log.php
DOCS=		guide.txt
EXAMPLES=	composite.php firebug.php php_error_handler.php \
		console.php mail.php sql.php display.php null.php \
		sqlite.php error_log.php observer_mail.php syslog.php \
		file.php pear_error_handler.php win.php
TESTS=		composite.phpt extract-zend2.2.phpt priority.phpt \
		console.phpt factory.phpt singleton.phpt \
		display.phpt file.phpt sql_ident.phpt \
		error_log.phpt firebug.phpt sqlite.phpt \
		extract-zend1.phpt levels.phpt \
		extract-zend2.0.phpt null.phpt
SQLS=		log.sql

_EXAMPLESDIR=	docs/examples
_SQLSDIR=	misc

LATEST_LINK=	pear-Log
OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PHP_SQLITE "PHP sqlite support (php5 only)" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PHP_SQLITE)
USE_PHP+=	sqlite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
