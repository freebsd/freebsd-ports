# New ports collection makefile for: hs-snap
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	snap
PORTVERSION=	0.9.0.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Snap: project starter executable and glue code library

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	aeson>=0.6 attoparsec>=0.10 cereal>=0.3 clientsession>=0.7.3.6 \
		configurator>=0.1 data-lens>=2.0.1 data-lens-template>=2.1 \
		directory-tree>=0.10 hashable>=1.1 heist>=0.7 logict>=0.4.2 \
		MonadCatchIO-transformers>=0.2 mtl>2.0 mwc-random>=0.8 \
		pwstore-fast>=2.2 snap-core>=0.9 snap-server>=0.9 stm>=2.2 \
		syb>=0.1 text>=0.11 transformers>=0.2 unordered-containers>=0.1.4 \
		utf8-string>=0.3 vector>=0.7.1 vector-algorithms>=0.4 \
		xmlhtml>=0.1

EXECUTABLE=	snap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
