# $FreeBSD$

PORTNAME=	yesod-json
PORTVERSION=	1.1.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Generate content for Yesod using the aeson package

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 attoparsec-conduit>=0.5 blaze-builder \
		conduit>=0.5 safe>=0.2 shakespeare-js>=1.0 text>=0.8 \
		transformers>=0.2.2 vector>=0.9 wai>=1.3 wai-extra>=1.3 \
		yesod-core>=1.1 yesod-routes>=1.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
