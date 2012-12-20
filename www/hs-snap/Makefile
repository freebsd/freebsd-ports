# $FreeBSD$

PORTNAME=	snap
PORTVERSION=	0.9.2.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Top-level package for the Snap Web Framework

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	aeson>=0.6 attoparsec>=0.10 cereal>=0.3 clientsession>=0.8 \
		configurator>=0.1 data-lens>=2.0.1 data-lens-template>=2.1 \
		directory-tree>=0.10 hashable>=1.1 heist>=0.7 logict>=0.4.2 \
		MonadCatchIO-transformers>=0.2 mtl>2.0 mwc-random>=0.8 \
		pwstore-fast>=2.3 snap-core>=0.9.2 snap-server>=0.9.2 \
		stm>=2.2 syb>=0.1 text>=0.11 transformers>=0.2 \
		unordered-containers>=0.1.4 utf8-string>=0.3 vector>=0.7.1 \
		vector-algorithms>=0.4 xmlhtml>=0.1

EXECUTABLE=	snap

IGNORE_DYNAMIC=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
