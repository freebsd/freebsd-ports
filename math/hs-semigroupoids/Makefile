# $FreeBSD$

PORTNAME=	semigroupoids
PORTVERSION=	5.2.2
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Semigroupoids: Category sans id

LICENSE=	BSD3CLAUSE

USE_CABAL=	base-orphans>=0.3 bifunctors>=5.0 comonad>=4.2.6 \
		contravariant>=0.2.0.1 distributive>=0.2.2 \
		semigroups>=0.8.3.1 tagged>=0.7.3 transformers-compat>=0.3

FLAGS_ENABLE=	containers contravariant distributive comonad tagged
FLAGS_DISABLE=	doctests

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
