# New ports collection makefile for: hs-yesod-json
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-json
PORTVERSION=	0.2.3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Generate content for Yesod using the aeson package

LICENSE=	BSD

USE_CABAL=	aeson>=0.3 attoparsec-enumerator>=0.3 blaze-builder \
		shakespeare-js>=0.10 text>=0.8 transformers>=0.2.2 \
		unordered-containers vector>=0.9 yesod-core>=0.9

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
