# Ports collection makefile for:  pear-Net_Dict
# Date created:			  07 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_Dict
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	net www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR interface to the DICT protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/Cache/Cache.php:${PORTSDIR}/sysutils/pear-Cache
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Dict.php
DOCS=		dict.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
