# $FreeBSD$

PORTNAME=	yesod-core
PORTVERSION=	1.2.19
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 case-insensitive>=0.2 cereal>=0.3 \
		clientsession>=0.9 conduit>=1.0.11 conduit-extra \
		cookie>=0.4.1 data-default exceptions fast-logger>=0.2 \
		http-types>=0.7 lifted-base>=0.1.2 monad-control>=0.3 \
		monad-logger>=0.3.1 mtl parsec>=2 path-pieces>=0.1.2 \
		random>=1.0.0.2 resourcet>=0.4.9 safe shakespeare>=1.0 \
		text>=0.7 transformers-base>=0.4 unix-compat vector>=0.9 \
		wai>=1.4 wai-extra>=1.3 wai-logger>=0.2 warp>=1.3.8 \
		yesod-routes>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
