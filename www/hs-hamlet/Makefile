# $FreeBSD$

PORTNAME=	hamlet
PORTVERSION=	1.1.7.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haml-like template files that are compile-time checked

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.2 blaze-html>=0.5 blaze-markup>=0.5.1 \
		failure>=0.1 parsec>=2 shakespeare>=1.0.1 text>=0.7

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
