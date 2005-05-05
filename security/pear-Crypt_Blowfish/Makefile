# Ports collection makefile for:  pear-Crypt_Blowfish
# Date created:			  27 April 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_Blowfish
PORTVERSION=	1.0.0
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for blowfish encryption

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Crypt
FILES=		Blowfish.php Blowfish/DefaultKey.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
