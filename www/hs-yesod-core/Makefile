# New ports collection makefile for: hs-yesod-core
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-core
PORTVERSION=	1.0.1.2
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 case-insensitive>=0.2 cereal>=0.3 \
		clientsession>=0.7.3.1 conduit>=0.4 cookie>=0.4 failure>=0.2 \
		fast-logger>=0.0.2 hamlet>=1.0 http-types>=0.6.5 lifted-base>=0.1 \
		monad-control>=0.3 parsec>=2 path-pieces>=0.1 random>=1.0.0.2 \
		resourcet>=0.3 shakespeare>=1.0 shakespeare-css>=1.0 \
		shakespeare-i18n>=1.0 shakespeare-js>=1.0 text>=0.7 \
		transformers>=0.2.2 transformers-base>=0.4 vector>=0.9 wai>=1.2 \
		wai-extra>=1.2 wai-logger>=0.0.1 yesod-routes>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
