# $FreeBSD$

PORTNAME=	DRBG
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Deterministic random bit generator based HMACs, Hashes, and Ciphers

LICENSE=	BSD3CLAUSE

USE_CABAL=	cereal>=0.2 cipher-aes128>=0.6 crypto-api>=0.13 \
		cryptohash-cryptoapi>=0.1 entropy mtl>=2.0 parallel \
		prettyclass tagged>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
