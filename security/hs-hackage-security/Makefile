# $FreeBSD$

PORTNAME=	hackage-security
PORTVERSION=	0.5.3.0
PORTREVISION=	3
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The hackage security library provides both server and client utilities for securing the Hackage package server

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	base16-bytestring base64-bytestring cryptohash-sha256 ed25519 \
		mtl network network-uri old-locale old-time tar zlib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
