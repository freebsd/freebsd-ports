# Ports collection makefile for:	pear-Net_NNTP
# Date created:				07 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	Net_NNTP
PORTVERSION=	1.2.0
CATEGORIES=	net news www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		NNTP/Client.php NNTP/Header.php NNTP/Message.php \
		NNTP/Protocol/Client.php
EXAMPLES=	index.php group.php read.php
_EXAMPLESDIR=	docs/examples/news.php.net

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
