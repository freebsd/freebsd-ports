# $FreeBSD$

PORTNAME=	warp
PORTVERSION=	1.3.8.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, light-weight web server for WAI applications

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-builder-conduit>=0.5 \
		case-insensitive>=0.2 conduit>=0.5 hashable http-types>=0.7 \
		lifted-base>=0.1 network>=2.3 network-conduit>=0.5 \
		simple-sendfile>=0.2.7 transformers>=0.2.2 unix-compat>=0.2 \
		void wai>=1.3

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
