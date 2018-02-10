# $FreeBSD$

PORTNAME=	angel
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	sysutils haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Process management and supervision daemon

LICENSE=	BSD3CLAUSE

USE_CABAL=	configurator>=0.1 mtl old-locale optparse-applicative \
		stm>=2.0 text>=0.11 unordered-containers>=0.1.4

EXECUTABLE=	angel

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
