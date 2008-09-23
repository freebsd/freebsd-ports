# New ports collection makefile for:	pear-Crypt_XXTEA
# Date created:		2008-09-22
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt_XXTEA
PORTVERSION=	0.9.0
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XXTEA encryption algorithm

BUILD_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS+=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Crypt/XXTEA.php
TESTS=		decrypt.phpt encrypt.phpt long2str.phpt setkey.phpt \
		str2long.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
