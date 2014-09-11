# $FreeBSD$

PORTNAME=	snap-server
PORTVERSION=	0.9.4.5
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, iteratee-based, epoll-enabled web server for the Snap Framework

LICENSE=	BSD3CLAUSE

USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 \
		blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2.0 \
		case-insensitive>=0.3 enumerator>=0.4.15 \
		MonadCatchIO-transformers>=0.2.1 mtl>=2 network>=2.3 \
		snap-core>=0.9.3 text>=0.11 unix-compat>=0.2

FLAGS_DEFINE=		OPENSSL

OPENSSL_DESC=		Enable HTTPS support using the HsOpenSSL library
OPENSSL_FLAG_ENABLE=	openssl
OPENSSL_FLAG_CABAL=	HsOpenSSL>=0.10

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
