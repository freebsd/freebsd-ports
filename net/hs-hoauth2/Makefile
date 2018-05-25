# $FreeBSD$

PORTNAME=	hoauth2
PORTVERSION=	1.7.1
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell OAuth2 authentication

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson http-conduit http-types microlens unordered-containers \
		uri-bytestring uri-bytestring-aeson wai warp

FLAGS_DISABLE=	test

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
