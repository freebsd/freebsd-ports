# Ports collection makefile for:  pear-HTTP
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP
PORTVERSION=	1.2.2
CATEGORIES=	www devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR miscellaneous HTTP utilities

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTTP.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
