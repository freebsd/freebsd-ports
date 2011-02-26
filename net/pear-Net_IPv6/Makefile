# Ports collection makefile for:  pear-Net_IPv6
# Date created:			  25 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_IPv6
DISTVERSION=	1.2.1
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Check and validate IPv6 addresses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

PEAR_CATSRC=	yes
CATEGORY=	Net
FILES=		IPv6.php
TESTS=		AllTests.php NetIPv6Test.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
