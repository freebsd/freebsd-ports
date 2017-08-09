# $FreeBSD$

PORTNAME=	http-reverse-proxy
PORTVERSION=	0.4.4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Reverse proxy HTTP requests, either over raw sockets or with WAI

LICENSE=	BSD3CLAUSE

USE_CABAL=	async blaze-builder>=0.3 case-insensitive>=0.4 conduit>=1.1 \
		conduit-extra data-default-class http-client>=0.3 \
		http-types>=0.6 lifted-base>=0.1 monad-control>=0.3 \
		network resourcet streaming-commons text>=0.11 wai>=3.0 \
		wai-logger word8>=0.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
