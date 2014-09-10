# $FreeBSD$

PORTNAME=	http-conduit
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client package with conduit interface and HTTPS support

LICENSE=	BSD3CLAUSE

USE_CABAL=	conduit>=0.5.5 http-client>=0.3.6 http-client-tls>=0.2.2 \
		http-types>=0.7 lifted-base>=0.1 monad-control mtl \
		resourcet>=1.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
