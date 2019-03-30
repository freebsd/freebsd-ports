# $FreeBSD$

PORTNAME=	DRBG
PORTVERSION=	0.5.5
PORTREVISION=	4
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Deterministic random bit generator based HMACs, Hashes, and Ciphers

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	cereal>=0.2 cipher-aes128>=0.6 crypto-api>=0.13 \
		cryptohash-cryptoapi>=0.1 entropy mtl>=2.0 parallel \
		prettyclass tagged>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
