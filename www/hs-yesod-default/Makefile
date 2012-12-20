# $FreeBSD$

PORTNAME=	yesod-default
PORTVERSION=	1.1.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Default config and main functions for your yesod application

LICENSE=	MIT

USE_CABAL=	data-default hamlet>=1.1 network-conduit>=0.5 safe \
		shakespeare-css>=1.0 shakespeare-js>=1.0 text>=0.9 \
		transformers>=0.2.2 unordered-containers wai>=1.3 \
		wai-extra>=1.3 warp>=1.3 yaml>=0.8 yesod-core>=1.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
