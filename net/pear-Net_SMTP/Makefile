# Ports collection makefile for:  pear-Net_SMTP
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_SMTP
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the SMTP protocol

BUILD_DEPENDS=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL \
		${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
# The Auth_SASL package is no longer absolutely required, but it will be used if it is available.
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		SMTP.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
