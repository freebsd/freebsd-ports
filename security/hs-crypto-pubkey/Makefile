# $FreeBSD$

PORTNAME=	crypto-pubkey
PORTVERSION=	0.1.2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Public Key cryptography

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	crypto-numbers crypto-pubkey-types>=0.2 crypto-random-api>=0.2 \
		cryptohash>=0.8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
