# Ports collection makefile for:  pear-Crypt_GPG
# Date created:			  14 Jan 2008
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt_GPG
PORTVERSION=	0.6.0
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	GNU Privacy Guard (GPG)

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

CATEGORY=	Crypt
FILES=		GPG.php GPG/Exceptions.php GPG/Key.php \
		GPG/Signature.php GPG/UserId.php GPG/SubKey.php \
		GPG/Driver/Php.php GPG/Driver/GnuPG.php
TESTS=		PhpDriverTestCase.php DriverTestCase.php \
		GnuPGDriverTestCase.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
