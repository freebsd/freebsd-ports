# Ports collection makefile for:  pear-Log
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Log
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	sysutils www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR logging utilities

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Log.php Log/composite.php Log/console.php Log/error_log.php \
		Log/file.php Log/mail.php Log/mcal.php Log/observer.php \
		Log/sql.php Log/syslog.php Log/win.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
