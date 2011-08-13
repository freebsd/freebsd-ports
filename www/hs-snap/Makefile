# New ports collection makefile for: hs-snap
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	snap
PORTVERSION=	0.5.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Snap: project starter executable and glue code library

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	attoparsec>=0.8.0.2 blaze-builder>=0.2.1.4 bytestring-nums \
		cereal>=0.3 directory-tree>=0.10 dlist>=0.5 enumerator>=0.4.13.1 \
		heist>=0.5 hint>=0.3.3.1 MonadCatchIO-transformers>=0.2.1 \
		mtl>=2 snap-core>=0.5.2 snap-server>=0.5.2 text>=0.11 \
		unix-compat zlib

EXECUTABLE=	snap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
