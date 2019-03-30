# $FreeBSD$

PORTNAME=	hoauth2
PORTVERSION=	1.7.1
PORTREVISION=	2
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell OAuth2 authentication

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson http-conduit http-types microlens unordered-containers \
		uri-bytestring uri-bytestring-aeson wai warp

FLAGS_DISABLE=	test

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
