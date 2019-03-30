# $FreeBSD$

PORTNAME=	heist
PORTVERSION=	1.1.0.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell template system supporting both HTML5 and XML

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson attoparsec blaze-builder blaze-html directory-tree \
		dlist hashable lifted-base map-syntax monad-control mtl \
		random transformers-base unordered-containers vector \
		xmlhtml

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
