# $FreeBSD$

PORTNAME=	http-reverse-proxy
PORTVERSION=	0.1.1.6
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Reverse proxy HTTP requests, either over raw sockets or with WAI

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.3 case-insensitive>=0.4 classy-prelude>=0.3 \
		conduit>=0.5 data-default http-conduit>=1.6 http-types>=0.6 \
		lifted-base>=0.1 monad-control>=0.3 network network-conduit>=0.6 \
		text>=0.11 wai>=1.3 warp>=1.3.4 word8>=0.0

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
