# New ports collection makefile for: hs-data-lens
# Date created:        November 19, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	data-lens
PORTVERSION=	2.0.2
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell 98 lenses

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	comonad>=1.1 comonad-transformers>=2.0 contravariant>=0.1.2 \
		distributive>=0.2 semigroupoids>=1.2.4 transformers>=0.2.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
