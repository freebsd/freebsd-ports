# New ports collection makefile for: hs-cprng-aes
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cprng-aes
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Crypto Pseudo Random Number Generator using AES

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	cereal>=0.3.0 crypto-api>=0.8 cryptocipher>=0.2.5 entropy>=0.2 \
		random

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
