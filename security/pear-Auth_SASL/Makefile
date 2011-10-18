# Ports collection makefile for:  pear-Auth_SASL
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth_SASL
PORTVERSION=	1.0.6
CATEGORIES=	security www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR abstraction of various SASL mechanism responses

BUILD_DEPENDS=	${PEARDIR}/Auth/Auth.php:${PORTSDIR}/security/pear-Auth
RUN_DEPENDS=	${PEARDIR}/Auth/Auth.php:${PORTSDIR}/security/pear-Auth

FILES=		Auth/SASL.php Auth/SASL/Anonymous.php \
		Auth/SASL/Common.php Auth/SASL/CramMD5.php \
		Auth/SASL/External.php Auth/SASL/DigestMD5.php \
		Auth/SASL/Login.php Auth/SASL/Plain.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
