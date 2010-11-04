# Ports collection makefile for:  pear-Auth_RADIUS
# Date created:			  11 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Auth_RADIUS
PORTVERSION=	1.0.7
CATEGORIES=	net security pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR wrapper classes for the RADIUS PECL

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	radius

CATEGORY=	Auth
FILES=		RADIUS.php
EXAMPLES=	radius-acct.php radius-auth.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
