# $FreeBSD$

PORTNAME=	semigroupoids
PORTVERSION=	5.3.1
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Semigroupoids: Category sans id

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	base-orphans>=0.3 bifunctors>=5.0 comonad>=4.2.6 \
		distributive>=0.2.2 semigroups>=0.8.3.1 tagged>=0.7.3 \
		transformers-compat>=0.3

FLAGS_ENABLE=	containers contravariant distributive comonad tagged
FLAGS_DISABLE=	doctests

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
