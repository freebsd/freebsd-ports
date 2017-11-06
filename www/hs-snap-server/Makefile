# $FreeBSD$

PORTNAME=	snap-server
PORTVERSION=	1.0.2.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, iteratee-based, epoll-enabled web server for the Snap Framework

LICENSE=	BSD3CLAUSE

USE_CABAL=	attoparsec blaze-builder case-insensitive clock io-streams \
		io-streams-haproxy lifted-base mtl network old-locale snap-core \
		text unix-compat vector

FLAGS_DEFINE=		OPENSSL

OPENSSL_DESC=		Enable HTTPS support using the HsOpenSSL library
OPENSSL_FLAG_ENABLE=	openssl
OPENSSL_FLAG_CABAL=	HsOpenSSL>=0.10

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
