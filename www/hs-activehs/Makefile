# $FreeBSD$

PORTNAME=	activehs
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell code presentation tool

LICENSE=	BSD

USE_CABAL=	activehs-base>=0.2 blaze-html>=0.5 blaze-markup>=0.5.1.0 \
		cmdargs>=0.7 data-pprint>=0.2 dia-base>=0.1 \
		dia-functions>=0.2.1.1 haskell-src-exts>=1.12 \
		highlighting-kate>=0.5 hint>=0.3.3.2 hoogle>=4.2.11 mtl>=2.0 \
		pandoc>=1.10 pureMD5>=2.1 QuickCheck>=2.4 simple-reflect>=0.2 \
		snap-core>=0.6 snap-server>=0.6 split>=0.1 syb>=0.2 \
		text>=0.11 utf8-string>=0.3 xhtml>=3000.2

STANDALONE=	yes
EXECUTABLE=	activehs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
