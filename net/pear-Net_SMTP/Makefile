# Ports collection makefile for:  pear-Net_SMTP
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_SMTP
PORTVERSION=	1.4.2
CATEGORIES=	net mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the SMTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		SMTP.php
DOCS=		guide.txt
TESTS=		auth.phpt basic.phpt config.php.dist quotedata.phpt
EXAMPLES=	basic.php

LATEST_LINK=	pear-Net_SMTP
OPTIONS=	PEAR_AUTH_SASL "PEAR::Auth_SASL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_AUTH_SASL)
BUILD_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
