# Ports collection makefile for:  pear-Crypt_CBC
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_CBC
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	security www pear

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	PEAR class to emulate Perl's Crypt::CBC module

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Crypt
FILES=		CBC.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
