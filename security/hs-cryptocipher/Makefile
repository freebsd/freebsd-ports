# New ports collection makefile for: hs-cryptocipher
# Date created:        November 19, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cryptocipher
PORTVERSION=	0.3.0
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Symmetrical Block, Stream, and PubKey Ciphers

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	cereal crypto-api>=0.5 crypto-pubkey-types primitive tagged \
		vector>=0.7

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
