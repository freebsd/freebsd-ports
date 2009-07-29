# Ports collection makefile for:  pear-Net_POP3
# Date created:			  10 August 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_POP3
PORTVERSION=	1.3.7
CATEGORIES=	net pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Provides a POP3 class to access POP3 server

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Net/POP3.php
DOCS=		examples/Net_POP3_example.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
