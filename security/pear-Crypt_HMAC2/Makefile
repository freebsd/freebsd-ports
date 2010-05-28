# Ports collection makefile for:	pear-Crypt_HMAC2
# Date created:				23 Nov, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt_HMAC2
PORTVERSION=	1.0.0
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Implementation of Hashed Message Authentication Code for PHP5

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

#CATEGORY=	Crypt
FILES=		Crypt/HMAC2.php Crypt/HMAC2/Exception.php
TESTS=		AllTests.php HMAC2Test.php \
		TestConfiguration.php.dist \
		TestHelper.php
DOCS=		intro.xml

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
