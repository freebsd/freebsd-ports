# New ports collection makefile for: hs-yesod
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod
PORTVERSION=	1.0.1.6
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 fast-logger>=0.0.2 hamlet>=1.0 \
		http-types>=0.6.1 monad-control>=0.3 parsec>=2.1 \
		shakespeare-css>=1.0 shakespeare-js>=1.0 shakespeare-text>=1.0 \
		text>=0.11 transformers>=0.2.2 unix-compat>=0.2 wai>=1.2 \
		wai-extra>=1.2 wai-logger>=0.1.2 warp>=1.2 yesod-auth>=1.0 \
		yesod-core>=1.0 yesod-form>=1.0 yesod-json>=1.0 \
		yesod-persistent>=1.0

EXECUTABLE=	yesod

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
