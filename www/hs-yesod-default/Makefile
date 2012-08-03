# New ports collection makefile for: hs-yesod-default
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-default
PORTVERSION=	1.0.1.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Default config and main functions for your yesod application

LICENSE=	MIT

USE_CABAL=	network-conduit>=0.4 shakespeare-css>=1.0 shakespeare-js>=1.0 \
		text>=0.9 transformers>=0.2.2 unordered-containers \
		wai>=1.2 wai-extra>=1.2 warp>=1.2 yaml>=0.7 yesod-core>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
