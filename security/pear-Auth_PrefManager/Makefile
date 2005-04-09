# Ports collection makefile for:  pear-Auth_PrefManager
# Date created:			  05 April 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Auth_PrefManager
PORTVERSION=	1.1.4
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR preferences management class

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Auth
FILES=		PrefManager.php
DOCS=		PM_Example.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
