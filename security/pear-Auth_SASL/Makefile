# Ports collection makefile for:  pear-Auth_SASL
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth_SASL
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR abstraction of various SASL mechanism responses

BUILD_DEPENDS=	${PEARDIR}/Auth/Auth.php:${PORTSDIR}/security/pear-Auth
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Auth
FILES=		SASL.php SASL/Anonymous.php SASL/Common.php SASL/CramMD5.php \
		SASL/DigestMD5.php SASL/Login.php SASL/Plain.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
