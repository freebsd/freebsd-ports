# $FreeBSD$

PORTNAME=	hjsmin
PORTVERSION=	0.1.4.7
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell implementation of a javascript minifier

LICENSE=	BSD3CLAUSE

USE_CABAL=	blaze-builder>=0.2 language-javascript>=0.5.1 \
		optparse-applicative>=0.7 text>=0.8

EXECUTABLE=	hjsmin

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
