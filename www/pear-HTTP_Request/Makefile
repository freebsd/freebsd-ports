# Ports collection makefile for:  pear-HTTP_Request
# Date created:			  04 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Request
PORTVERSION=	1.2.4
CATEGORIES=	www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

BUILD_DEPENDS=	${PEARDIR}/Net/URL.php:${PORTSDIR}/net/pear-Net_URL		\
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		Request.php Request/Listener.php
EXAMPLES=	download-progress.php example.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
