# $FreeBSD$

PORTNAME=	tls-extra
PORTVERSION=	0.5.0
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	TLS extra default values and helpers

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	certificate>=1.3.0 cipher-aes>=0.1 crypto-api>=0.5 \
		cryptocipher>=0.3.0 cryptohash>=0.6 mtl network>=2.3 \
		pem>=0.1.0 text>=0.5 tls>=1.0.0 vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
