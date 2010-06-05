# Ports collection makefile for:  pear-Net_Whois
# Date created:			  2006/12/22
# Whom:				  chinsan
#
# $FreeBSD$
#

PORTNAME=	Net_Whois
PORTVERSION=	1.0.3
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A tool to query internet domain name services

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket

CATEGORY=	Net
FILES=		Whois.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
