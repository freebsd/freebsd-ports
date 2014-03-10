# $FreeBSD$

PORTNAME=	yesod-static
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Static file serving subsite for Yesod Web Framework

LICENSE=	MIT

USE_CABAL=	base64-bytestring>=0.1.0.1 cereal>=0.3 conduit>=0.5 \
		crypto-conduit>=0.4 cryptohash>=0.6.1 data-default \
		file-embed>=0.0.4.1 http-types>=0.7 shakespeare-css>=1.0.3 \
		system-fileio>=0.3 system-filepath>=0.4.6 text>=0.9 \
		transformers>=0.2.2 unix-compat>=0.2 wai>=1.3 \
		wai-app-static>=1.3 yesod-core>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
