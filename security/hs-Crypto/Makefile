# $FreeBSD$

PORTNAME=	Crypto
PORTVERSION=	4.2.5.1
PORTREVISION=	3
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Collects together existing Haskell cryptographic functions

USE_CABAL=	HUnit QuickCheck>=2.4.0.1 random

EXECUTABLE=	HMACTest QuickTest RSATest SHA1Test SymmetricTest WordListTest

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
