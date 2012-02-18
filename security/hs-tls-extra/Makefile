# New ports collection makefile for: hs-tls-extra
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tls-extra
PORTVERSION=	0.4.2.1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	TLS extra default values and helpers

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	certificate>=1.0.0 crypto-api>=0.5 cryptocipher>=0.3.0 \
		cryptohash>=0.6 mtl network>=2.3 text>=0.5 tls>=0.8.4 \
		vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
