# $FreeBSD$

PORTNAME=	yesod-core
PORTVERSION=	1.2.0.4
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 attoparsec-conduit blaze-builder>=0.2.1.4 \
		blaze-html>=0.5 blaze-markup>=0.5.1 case-insensitive>=0.2 \
		cereal>=0.3 clientsession>=0.9 conduit>=0.5 cookie>=0.4 \
		data-default failure>=0.2 fast-logger>=0.2 hamlet>=1.1 \
		http-types>=0.7 lifted-base>=0.1 monad-control>=0.3 \
		monad-logger>=0.3.1 parsec>=2 path-pieces>=0.1.2 \
		random>=1.0.0.2 resourcet>=0.4.6 safe shakespeare>=1.0 \
		shakespeare-css>=1.0 shakespeare-i18n>=1.0 shakespeare-js>=1.0.2 \
		text>=0.7 transformers>=0.2.2 transformers-base>=0.4 \
		vector>=0.9 wai>=1.4 wai-extra>=1.3 warp>=1.3.8 \
		yesod-routes>=1.2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
