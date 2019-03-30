# $FreeBSD$

PORTNAME=	crypto-pubkey
PORTVERSION=	0.2.8
PORTREVISION=	5
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Public Key cryptography

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	byteable crypto-numbers>=0.2.2 crypto-pubkey-types>=0.4.1 \
		crypto-random>=0.0.0 cryptohash>=0.9.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
