# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.8.5
CATEGORIES=	sysutils www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Log.php Log/composite.php Log/console.php Log/display.php	\
		Log/error_log.php Log/file.php Log/mail.php Log/mcal.php	\
		Log/null.php Log/observer.php Log/sql.php Log/sqlite.php	\
		Log/syslog.php Log/win.php
DOCS=		guide.txt
EXAMPLES=	composite.php console.php display.php error_log.php file.php	\
		mail.php null.php observer_mail.php pear_error_handler.php	\
		php_error_handler.php sql.php sqlite.php syslog.php win.php
TESTS=		composite.phpt console.phpt display.phpt error_log.phpt		\
		extract.phpt extract2.phpt factory.phpt null.phpt priority.phpt	\
		singleton.phpt sqlite.phpt sql_ident.phpt
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
