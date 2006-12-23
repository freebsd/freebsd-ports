# Ports collection makefile for:  pear-Net_CheckIP
# Date created:			  29 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_CheckIP
PORTVERSION=	1.2.1
CATEGORIES=	net pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Check the syntax of IPv4 addresses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		CheckIP.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
