# Ports collection makefile for:  pear-Net_CheckIP
# Date created:			  29 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_CheckIP
PORTVERSION=	1.1
CATEGORIES=	net pear

MAINTAINER=	antonio@php.net
COMMENT=	Check the syntax of IPv4 addresses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		CheckIP.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
