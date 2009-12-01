# Ports collection makefile for:  pear-Crypt_CHAP
# Date created:			  09 March 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_CHAP
PORTVERSION=	1.0.2
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for generating CHAP packets

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	mcrypt mhash

CATEGORY=	Crypt
FILES=		CHAP.php
TESTS=		chaptest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
