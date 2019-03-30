# $FreeBSD$

PORTNAME=	snap-core
PORTVERSION=	1.0.3.2
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Snap: A Haskell Web Framework (core interfaces and types)

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	attoparsec case-insensitive hashable HUnit io-streams \
		lifted-base monad-control mtl network-uri old-locale \
		random readable regex-posix time-locale-compat \
		transformers-base unix-compat unordered-containers \
		vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
