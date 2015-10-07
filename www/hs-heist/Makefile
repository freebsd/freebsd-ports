# $FreeBSD$

PORTNAME=	heist
PORTVERSION=	0.14.1.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell template system supporting both HTML5 and XML

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.6 attoparsec>=0.10 blaze-builder>=0.2 \
		blaze-html>=0.4 directory-tree>=0.10 dlist>=0.5 either>=3.1 \
		hashable>=1.1 map-syntax>=0.2 \
		MonadCatchIO-transformers>=0.2.1 mtl>=2.0 random>=1.0.1.0 \
		text>=0.10 unordered-containers>=0.1.4 vector>=0.9 \
		xmlhtml>=0.2.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
