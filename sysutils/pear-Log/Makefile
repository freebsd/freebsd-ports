# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.12.0
CATEGORIES=	sysutils www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
IGNORE_WITH_PHP=	4

FILES=		Log/composite.php Log/console.php Log/daemon.php \
		Log/display.php Log/error_log.php Log/file.php \
		Log/firebug.php Log/mail.php Log/mcal.php Log/mdb2.php \
		Log/null.php Log/observer.php Log/sql.php Log/sqlite.php \
		Log/syslog.php Log/win.php Log.php
DOCS=		guide.txt
EXAMPLES=	composite.php console.php display.php error_log.php \
		file.php firebug.php mail.php null.php observer_mail.php \
		pear_error_handler.php php_error_handler.php sql.php \
		sqlite.php syslog.php win.php
TESTS=		backtrace.phpt composite.phpt console.phpt \
		display.phpt error_log.phpt format.phpt \
		extract-zend2.0.phpt extract-zend2.2.phpt \
		factory.phpt file.phpt firebug.phpt levels.phpt null.phpt \
		priority.phpt singleton.phpt sqlite.phpt sql_ident.phpt
SQLS=		log.sql

_SQLSDIR=	misc

LATEST_LINK=	pear-Log
OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_Mail "PEAR::Mail support" off \
		PHP_SQLITE "PHP sqlite support (php5 only)" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_Mail)
BUILD_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if defined(WITH_PHP_SQLITE)
USE_PHP+=	sqlite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
