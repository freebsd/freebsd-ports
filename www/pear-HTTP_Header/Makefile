# Ports collection makefile for:  pear-HTTP_Header
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Header
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	www devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR OO-Interface to modify HTTP-Headers easily

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:${PORTSDIR}/www/pear-HTTP
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTTP
FILES=		Header.php Header/Cache.php
EXAMPLES=	Header_Cache.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
