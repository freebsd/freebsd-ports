# Ports collection makefile for:  pear-File_Gettext
# Date created:			  01 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	File_Gettext
PORTVERSION=	0.3.3
CATEGORIES=	sysutils devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR GNU Gettext file parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

CATEGORY=	File
FILES=		Gettext.php Gettext/MO.php Gettext/PO.php

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 410
IGNORE=		"You need PHP 4.1.0 or later to install PEAR::File_Gettext"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
