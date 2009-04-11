# Ports collection makefile for:  pear-Services_SharedBook
# Date created:			  22 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Services_SharedBook
PORTVERSION=	0.2.2
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP wrapper for SharedBook Open API

BUILD_DEPENDS=	${PEARDIR}/HTTP/Client.php:${PORTSDIR}/www/pear-HTTP_Client
RUN_DEPENDS=	${PEARDIR}/HTTP/Client.php:${PORTSDIR}/www/pear-HTTP_Client

FILES=		Services/SharedBook.php Services/SharedBook/Exception.php

EXAMPLES=	example.php photo1.jpg photo2.jpg photo3.jpg photo4.jpg

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
