# Ports collection makefile for:  pear-Net_Sieve
# Date created:			  25 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_Sieve
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	net www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class to handle talking to timsieved

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}/Net
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Net/Sieve.php
	@${CHMOD} a-x ${PEARDIR}/Net/Sieve.php

.include <bsd.port.post.mk>
