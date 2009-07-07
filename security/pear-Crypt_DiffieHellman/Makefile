# Ports collection makefile for:  pear-Crypt_DiffieHellman
# Date created:			  27 Jan 2008
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt_DiffieHellman
PORTVERSION=	0.2.3
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class implementing Diffie-Hellman Key Exchange protocol for PHP5

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	bcmath mbstring gmp

CATEGORY=	Crypt
FILES=		DiffieHellman.php DiffieHellman/Math.php DiffieHellman/Exception.php \
		DiffieHellman/Math/Exception.php DiffieHellman/Math/BigInteger.php \
		DiffieHellman/Math/BigInteger/Interface.php DiffieHellman/Math/BigInteger/Gmp.php \
		DiffieHellman/Math/BigInteger/Exception.php DiffieHellman/Math/BigInteger/Bcmath.php
TESTS=		AllTests.php DiffieHellmanTest.php TestHelper.php TestConfiguration.php.dist

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
