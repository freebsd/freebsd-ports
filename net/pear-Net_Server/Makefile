# Ports collection makefile for:  pear-Net_Server
# Date created:			  23 Octobre 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_Server
PORTVERSION=	0.12.0
CATEGORIES=	net pear

MAINTAINER=	tux@pinguru.net
COMMENT=	Generic server class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	sockets pcntl
CATEGORY=	Net
FILES=		Server.php \
		Server/Driver.php Server/Handler.php \
		Server/Driver/Fork.php Server/Driver/Sequential.php
DOCS=		todo.txt
EXAMPLES=	talkback.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
