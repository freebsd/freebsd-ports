# Ports collection makefile for:  pear-Auth_RADIUS
# Date created:			  11 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Auth_RADIUS
PORTVERSION=	1.0.4
CATEGORIES=	net security pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR wrapper classes for the RADIUS PECL

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	radius

CATEGORY=	Auth
FILES=		RADIUS.php
EXAMPLES=	radius-acct.php radius-auth.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
