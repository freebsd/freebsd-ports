# $FreeBSD$

PORTNAME=	hoauth2
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell OAuth2 authentication

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.7 bytestring-show>=0.3.5 http-conduit>=2.0 \
		http-types>=0.8 monad-control>=0.3 mtl>=1 random text>=0.11

FLAGS_DISABLE=	test

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
