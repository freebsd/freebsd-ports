# $FreeBSD$

PORTNAME=	RSA
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementation of RSA, using the padding schemes of PKCS#1 v2.1

LICENSE=	BSD3CLAUSE

USE_CABAL=	crypto-api>=0.10 crypto-pubkey-types>=0.2 DRBG>=0.5.2 \
		monadcryptorandom>0 pureMD5>0 QuickCheck>=2.5 SHA>0 \
		tagged>=0.2 test-framework>=0.8.0.3 \
		test-framework-quickcheck2>=0.3.0.2

FLAGS_DISABLE=	BuildTestExecutable

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
