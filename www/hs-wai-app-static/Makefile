# $FreeBSD$

PORTNAME=	wai-app-static
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	WAI application for static serving

LICENSE=	MIT

USE_CABAL=	base64-bytestring>=0.1 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 byteable cryptohash>=0.11 \
		cryptohash-conduit file-embed>=0.0.3.1 http-date \
		http-types>=0.7 mime-types>=0.1 optparse-applicative>=0.7 \
		system-fileio>=0.3 system-filepath>=0.4 text>=0.7 \
		unix-compat>=0.2 unordered-containers>=0.2 wai>=3.0 \
		wai-extra>=3.0 warp>=3.0 zlib>=0.5

EXECUTABLE=	warp

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
