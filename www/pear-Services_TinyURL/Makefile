# Ports collection makefile for:  pear-Services_TinyURL
# Date created:			  22 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Services_TinyURL
PORTVERSION=	0.1.2
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to TinyURL's API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	curl

FILES=		Services/TinyURL.php Services/TinyURL/Exception.php

TESTS=		001-create.phpt 002-lookup.phpt 003-create-and-lookup.phpt \
		100-bug-12207.phpt tests-config.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
