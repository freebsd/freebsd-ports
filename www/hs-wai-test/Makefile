# $FreeBSD$

PORTNAME=	wai-test
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Unit test framework (built on HUnit) for WAI applications

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-builder-conduit>=0.5 \
		case-insensitive>=0.2 conduit>=0.5 cookie>=0.2 \
		http-types>=0.7 HUnit>=1.2 network text>=0.7 \
		transformers>=0.2.2 wai>=1.3

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
