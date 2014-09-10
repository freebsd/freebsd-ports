# $FreeBSD$

PORTNAME=	warp
PORTVERSION=	3.0.0.5
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, light-weight web server for WAI applications

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.3.3 case-insensitive>=0.2 hashable \
		http-date http-types>=0.8.5 network>=2.3 \
		simple-sendfile>=0.2.7 streaming-commons>=0.1.2 text \
		unix-compat>=0.2 void wai>=3.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
