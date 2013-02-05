# $FreeBSD$

PORTNAME=	cryptocipher
PORTVERSION=	0.4.0
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Symmetrical Block, Stream, and PubKey Ciphers

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	cereal cipher-aes cipher-rc4 cpu>=0.1 crypto-api>=0.5 \
		crypto-pubkey-types>=0.2 primitive tagged vector>=0.7

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
