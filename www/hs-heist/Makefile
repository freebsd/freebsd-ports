# $FreeBSD$

PORTNAME=	heist
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell template system supporting both HTML5 and XML

LICENSE=	BSD

USE_CABAL=	aeson>=0.6 attoparsec>=0.10 blaze-builder>=0.2 \
		blaze-html>=0.4 directory-tree>=0.10 dlist>=0.5 errors>=1.4 \
		hashable>=1.1 MonadCatchIO-transformers>=0.2.1 mtl>=2.0 \
		random>=1.0.1.0 text>=0.10 unordered-containers>=0.1.4 \
		vector>=0.9 xmlhtml>=0.1.6

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
