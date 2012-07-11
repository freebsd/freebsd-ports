# Ports collection makefile for:  pear-Net_Server
# Date created:			  23 Octobre 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_Server
PORTVERSION=	1.0.2
CATEGORIES=	net pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic server class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	sockets pcntl
CATEGORY=	Net
FILES=		Server.php \
		Server/Driver.php Server/Handler.php \
		Server/Driver/Fork.php Server/Driver/Sequential.php \
		Server/Driver/Multiprocess.php \
		Server/Driver/Multiprocess/MPM-prefork.php \
		Server/Driver/Multiprocess/Processor.php \
		Server/Driver/Multiprocess/remoteConsole.php
DOCS=		todo.txt
EXAMPLES=	talkback.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
