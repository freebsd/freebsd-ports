# Ports collection makefile for:  pear-Auth_SASL
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth_SASL
PORTVERSION=	1.0.1
CATEGORIES=	security www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR abstraction of various SASL mechanism responses

BUILD_DEPENDS=	${PEARDIR}/Auth/Auth.php:${PORTSDIR}/security/pear-Auth
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	SASL.php SASL

do-install:
.for FILE in ${MANIFEST}
	@${CP} -Rp ${WRKSRC}/${FILE} ${PEARDIR}/Auth
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Auth/${FILE}
.endfor
	@${CHMOD} a-x ${PEARDIR}/Auth/SASL/*
	@${CHMOD} a-x ${PEARDIR}/Auth/SASL.php

.include <bsd.port.post.mk>
