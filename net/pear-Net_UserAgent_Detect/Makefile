# Ports collection makefile for:  pear-Net_UserAgent_Detect
# Date created:			  04 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_UserAgent_Detect
PORTVERSION=	2.0.1
CATEGORIES=	net pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class that detects web browser, version and platform

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

CATEGORY=	Net/UserAgent
FILES=		Detect.php

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 410
IGNORE=		"You need PHP 4.1.0 or later to install PEAR::Net_UserAgent_Detect"
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
