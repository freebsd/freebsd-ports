# New ports collection makefile for: hs-heist
# Date created:        September 20, 2010
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	heist
PORTVERSION=	0.7.0.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An (x)html templating system

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	attoparsec>=0.10 blaze-builder>=0.2 directory-tree \
		MonadCatchIO-transformers>=0.2.1 mtl>=2.0 text>=0.10 \
		transformers xmlhtml>=0.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
