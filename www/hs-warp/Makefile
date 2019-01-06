# $FreeBSD$

PORTNAME=	warp
PORTVERSION=	3.2.22
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, light-weight web server for WAI applications

LICENSE=	MIT

USE_CABAL=	auto-update>=0.1.1 bsb-http-chunked case-insensitive>=0.2 \
		hashable http-date http-types>=0.8.5 http2>=1.0.2 \
		iproute>=1.3.1 network>=2.3 old-locale simple-sendfile>=0.2.7 \
		streaming-commons>=0.1.10 unix-compat>=0.2 vault>=0.3 \
		wai>=3.0 word8

FLAGS_ENABLE=	allow-sendfilefd
FLAGS_DISABLE=	network-bytestring warp-debug use-bytestring-builder

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
