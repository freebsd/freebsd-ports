# Ports collection makefile for:  pear-Net_IMAP
# Date created:			  12 march 2004
# Whom:				  Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	Net_IMAP
PORTVERSION=	1.0.3
CATEGORIES=	mail net pear

MAINTAINER=	rafan@infor.org
COMMENT=	PEAR class that provides an implementation of the IMAP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		IMAP.php IMAPProtocol.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
