# Ports collection makefile for:  pear-Net_Finger
# Date created:			  07 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_Finger
PORTVERSION=	1.0.0
CATEGORIES=	net www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class that provides a tool for querying finger servers

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Finger.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
