# New ports collection makefile for: hs-yesod-static
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-static
PORTVERSION=	1.0.0.3
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Static file serving subsite for Yesod Web Framework

LICENSE=	MIT

USE_CABAL=	base64-bytestring>=0.1.0.1 cereal>=0.3 conduit>=0.4 \
		crypto-conduit>=0.3 cryptohash>=0.6.1 file-embed>=0.0.4.1 \
		http-types>=0.6.5 text>=0.9 transformers>=0.2.2 \
		unix-compat>=0.2 wai>=1.2 wai-app-static>=1.2 yesod-core>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
