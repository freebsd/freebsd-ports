# $FreeBSD$

PORTNAME=	hoauth2
PORTVERSION=	0.5.9
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell OAuth2 authentication

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson http-conduit http-types text unordered-containers \
		wai warp

FLAGS_DISABLE=	test

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
