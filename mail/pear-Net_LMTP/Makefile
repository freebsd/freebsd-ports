# Ports collection makefile for:  pear-Net_LMTP
# Date created:			  07 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_LMTP
PORTVERSION=	1.0.1
CATEGORIES=	mail www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR implementation of the RFC2033 LMTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		LMTP.php
TESTS=		test_lmtp.php
_TESTSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
