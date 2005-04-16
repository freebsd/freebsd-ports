# Ports collection makefile for:  pear-Net_POP3
# Date created:			  10 August 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_POP3
PORTVERSION=	1.3.6
CATEGORIES=	net pear

MAINTAINER=	tux@pinguru.net
COMMENT=	Provides a POP3 class to access POP3 server

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		POP3.php
TESTS=		Net_POP3_example.php
_TESTSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
