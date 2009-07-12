# Ports collection makefile for:  pear-Net_Ping
# Date created:			  24 February 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_Ping
PORTVERSION=	2.4.4
CATEGORIES=	net pear

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PEAR class to execute ping

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Ping.php
EXAMPLES=	example.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
