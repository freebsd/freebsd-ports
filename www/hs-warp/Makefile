# New ports collection makefile for: hs-warp
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	warp
PORTVERSION=	1.2.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A fast, light-weight web server for WAI applications

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-builder-conduit>=0.4 \
		case-insensitive>=0.2 conduit>=0.4 http-types>=0.6 \
		lifted-base>=0.1 network>=2.3 network-conduit>=0.4 \
		simple-sendfile>=0.2.2 transformers>=0.2.2 unix-compat>=0.2 \
		wai>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
