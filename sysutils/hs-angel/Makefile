# $FreeBSD$

PORTNAME=	angel
PORTVERSION=	0.3.3
CATEGORIES=	sysutils haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Process management and supervision daemon

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	configurator>=0.1 MissingH mtl stm>=2.0 text>=0.11 \
		unordered-containers>=0.1.4

EXECUTABLE=	angel

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
