# New ports collection makefile for: hs-crypto-api
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	crypto-api
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A generic interface for cryptographic operations

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	cereal>=0.2 entropy largeword>=1.0.0 tagged>=0.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
