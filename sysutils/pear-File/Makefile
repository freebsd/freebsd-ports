# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
PORTVERSION=	1.1.0.r2
PORTEPOCH=	1
CATEGORIES=	sysutils www pear
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/RC/}

MAINTAINER=	antonio@php.net
COMMENT=	PEAR common file and directory routines

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

FILES=		File.php File/Util.php File/CSV.php
TESTS=		parser.php test.csv FileTest.php

.include <bsd.port.pre.mk>

PHP_VERS=       ${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 430
IGNORE=         "You need PHP 4.3.0 or later to install PEAR::File"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
