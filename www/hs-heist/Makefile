# $FreeBSD$

PORTNAME=	heist
PORTVERSION=	0.8.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An (x)html templating system

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	aeson>=0.6 attoparsec>=0.10 blaze-builder>=0.2 \
		blaze-html>=0.4 directory-tree MonadCatchIO-transformers>=0.2.1 \
		mtl>=2.0 random text>=0.10 unordered-containers>=0.1.4 \
		vector>=0.9 xmlhtml>=0.1.6

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
