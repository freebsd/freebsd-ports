# $FreeBSD$

PORTNAME=	angel
PORTVERSION=	0.3.4
PORTREVISION=	3
CATEGORIES=	sysutils haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Process management and supervision daemon

LICENSE=	BSD

USE_CABAL=	configurator>=0.1 MissingH mtl stm>=2.0 text>=0.11 \
		unordered-containers>=0.1.4

EXECUTABLE=	angel

STANDALONE=	yes

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
