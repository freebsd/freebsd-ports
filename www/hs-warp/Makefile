# New ports collection makefile for: hs-warp
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	warp
PORTVERSION=	0.3.2.3
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A fast, light-weight web server for WAI applications

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2 \
		enumerator>=0.4.5 sendfile>=0.7.2 transformers>=0.2 wai>=0.3.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
