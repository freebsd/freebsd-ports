# $FreeBSD$

PORTNAME=	pointed
PORTVERSION=	3.0.2
PORTREVISION=	3
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell 98 pointed and copointed data

LICENSE=	BSD

USE_CABAL=	comonad>=3 comonad-transformers>=3 data-default>=0.4 \
		semigroupoids>=3.0 semigroups>=0.8.3.1 stm>=2.1.2.1 \
		transformers>=0.2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
