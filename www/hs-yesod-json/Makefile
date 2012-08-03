# New ports collection makefile for: hs-yesod-json
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-json
PORTVERSION=	1.0.0.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Generate content for Yesod using the aeson package

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 attoparsec-conduit>=0.4 blaze-builder \
		conduit>=0.4 safe>=0.2 shakespeare-js>=1.0 text>=0.8 \
		transformers>=0.2.2 vector>=0.9 wai>=1.2 wai-extra>=1.2 \
		yesod-core>=1.0 yesod-routes>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
