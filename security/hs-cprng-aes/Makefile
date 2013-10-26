# $FreeBSD$

PORTNAME=	cprng-aes
PORTVERSION=	0.3.4
PORTREVISION=	3
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Crypto Pseudo Random Number Generator using AES

LICENSE=	BSD

USE_CABAL=	cipher-aes>=0.1 crypto-api>=0.8 crypto-random-api>=0.2 \
		entropy>=0.2 random

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
