# $FreeBSD$

PORTNAME=	cryptocipher
PORTVERSION=	0.6.2
PORTREVISION=	7
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Symmetrical block and stream ciphers

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	cipher-aes>=0.2.3 cipher-blowfish>=0.0 cipher-camellia>=0.0 \
		cipher-des>=0.0 cipher-rc4>=0.1.3 crypto-cipher-types>=0.0.8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
