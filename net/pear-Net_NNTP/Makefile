# Ports collection makefile for:	pear-Net_NNTP
# Date created:				07 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	Net_NNTP
PORTVERSION=	0.10.1
CATEGORIES=	net news www pear

MAINTAINER=	clement@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		NNTP.php NNTP/Protocol.php NNTP/Header.php NNTP/Message.php
EXAMPLES=	README read.php group.php index.php
_EXAMPLESDIR=	examples/news.php.net
 
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
