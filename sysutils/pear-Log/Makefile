# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.9.10
CATEGORIES=	sysutils www pear

MAINTAINER=	thomas@goodking.ca
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

FILES=		Log/composite.php Log/console.php Log/daemon.php Log/display.php \
		Log/error_log.php Log/file.php Log/mail.php Log/mcal.php \
		Log/mdb2.php Log/null.php Log/observer.php Log/sql.php \
		Log/sqlite.php Log/syslog.php Log/win.php Log.php
DOCS=		guide.txt
EXAMPLES=	composite.php console.php display.php error_log.php file.php \
		mail.php null.php observer_mail.php pear_error_handler.php \
		php_error_handler.php sql.php sqlite.php syslog.php win.php
TESTS=		composite.phpt console.phpt display.phpt error_log.phpt \
		extract-zend1.phpt extract-zend2.0.phpt extract-zend2.2.phpt \
		factory.phpt file.phpt levels.phpt null.phpt priority.phpt \
		singleton.phpt sqlite.phpt sql_ident.phpt

SQLS=		log.sql

_EXAMPLESDIR=	docs/examples
_SQLSDIR=	misc

LATEST_LINK=	pear-Log
OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off

.if exists(${LOCALBASE}/etc/php.conf)
.include "${LOCALBASE}/etc/php.conf"
.endif

.if defined(PHP_VER) && ${PHP_VER} == 5
OPTIONS+=	PHP_SQLITE "PHP sqlite support" off
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB2)
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PHP_SQLITE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/sqlite.so:${PORTSDIR}/databases/php5-sqlite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
