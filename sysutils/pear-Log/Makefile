# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.8.7
CATEGORIES=	sysutils www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

FILES=		Log/composite.php Log/console.php Log/daemon.php \
		Log/display.php Log/error_log.php Log/file.php Log/mail.php \
		Log/mcal.php Log/null.php Log/observer.php Log/sql.php \
		Log/sqlite.php Log/syslog.php Log/win.php Log.php
DOCS=		guide.txt
EXAMPLES=	composite.php console.php display.php error_log.php file.php \
		mail.php null.php observer_mail.php pear_error_handler.php \
		php_error_handler.php sql.php sqlite.php syslog.php win.php
TESTS=		composite.phpt console.phpt display.phpt error_log.phpt \
		extract.phpt extract2.phpt factory.phpt null.phpt priority.phpt \
		singleton.phpt sqlite.phpt sql_ident.phpt
SQLS=		log.sql

_EXAMPLESDIR=	docs/examples
_SQLSDIR=	misc

LATEST_LINK=	pear-Log
OPTIONS=	PEAR_DB "PEAR::DB support" off

LOCALBASE?=	/usr/local

.if exists(${LOCALBASE}/etc/php.conf)
.include "${LOCALBASE}/etc/php.conf"
.endif

.if defined(PHP_VER) && ${PHP_VER} == 5
OPTIONS+=	PHP_SQLITE "PHP sqlite support" off
.endif

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 430
IGNORE=		"You need PHP 4.3.0 or later to install PEAR::Log"
.endif

.if defined(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PHP_SQLITE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/${extension}.so:${PORTSDIR}/databases/php5-sqlite
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
