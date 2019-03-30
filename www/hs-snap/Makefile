# $FreeBSD$

PORTNAME=	snap
PORTVERSION=	1.1.1.0
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Top-level package for the Snap Web Framework

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson attoparsec cereal clientsession configurator \
		directory-tree dlist hashable heist lens lifted-base \
		map-syntax monad-control mtl mwc-random pwstore-fast \
		snap-core snap-server transformers-base \
		unordered-containers xmlhtml

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
