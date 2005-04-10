# Ports collection makefile for:  pear-Net_IPv6
# Date created:			  25 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_IPv6
PORTVERSION=	1.0.3
CATEGORIES=	net pear

MAINTAINER=	antonio@php.net
COMMENT=	Check and validate IPv6 addresses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		IPv6.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
