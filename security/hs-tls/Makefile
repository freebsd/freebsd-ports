# $FreeBSD$

PORTNAME=	tls
PORTVERSION=	1.0.2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	TLS/SSL protocol native implementation (Server and Client)

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	cereal>=0.3 certificate>=1.3.0 crypto-api>=0.5 \
		cryptocipher>=0.3.0 cryptohash>=0.6 mtl network

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
