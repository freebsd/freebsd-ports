# Ports collection makefile for:  pear-HTTP_Header
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Header
PORTVERSION=	1.1.1
CATEGORIES=	www devel pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR OO interface to modify and handle HTTP headers and status codes

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		Header.php Header/Cache.php
TESTS=		README.txt cacheresponse.php header.php header_cache.php response.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
