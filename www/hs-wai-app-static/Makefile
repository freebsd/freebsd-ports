# New ports collection makefile for: hs-wai-app-static
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wai-app-static
PORTVERSION=	1.2.0.4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	WAI application for static serving

LICENSE=	MIT

USE_CABAL=	base64-bytestring>=0.1 blaze-builder>=0.2.1.4 blaze-html>=0.4 \
		cryptohash>=0.7 file-embed>=0.0.3.1 http-date http-types>=0.6 \
		text>=0.7 transformers>=0.2.2 unix-compat>=0.2 wai>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
