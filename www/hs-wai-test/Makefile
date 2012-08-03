# New ports collection makefile for: hs-wai-test
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wai-test
PORTVERSION=	1.2.0.2
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Unit test framework (built on HUnit) for WAI applications

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-builder-conduit>=0.4 \
		case-insensitive>=0.2 conduit>=0.4 cookie>=0.2 \
		http-types>=0.6 HUnit>=1.2 text>=0.7 transformers>=0.2.2 \
		wai>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
