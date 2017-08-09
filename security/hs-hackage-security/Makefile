# $FreeBSD$

PORTNAME=	hackage-security
PORTVERSION=	0.5.2.2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The hackage security library provides both server and client utilities for securing the Hackage package server

LICENSE=	BSD3CLAUSE

USE_CABAL=	base16-bytestring base64-bytestring cryptohash-sha256 ed25519 \
		mtl network network-uri old-locale old-time parsec tar zlib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
