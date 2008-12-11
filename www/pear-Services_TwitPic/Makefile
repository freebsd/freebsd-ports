# Ports collection makefile for:  pear-Services_TwitPic
# Date created:			  10 Dez 2008
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_TwitPic
PORTVERSION=	0.1.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP Interface to TwitPic's API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Services/TwitPic.php Services/TwitPic/Exception.php \
		Services/TwitPic/Request/Common.php Services/TwitPic/Request/HTTPRequest.php \
		Services/TwitPic/Request/Mock.php
EXAMPLES=	example.php
_EXAMPLESDIR=	docs
TESTS=		TwitPicTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
