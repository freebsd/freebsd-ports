# $FreeBSD$

PORTNAME=	snap-server
PORTVERSION=	0.9.3.3
PORTREVISION=	4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, iteratee-based, epoll-enabled web server for the Snap Framework

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 \
		blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2.0 \
		case-insensitive>=0.3 enumerator>=0.4.15 \
		MonadCatchIO-transformers>=0.2.1 mtl>=2 network>=2.3 \
		snap-core>=0.9.3 text>=0.11 unix-compat>=0.2

OPTIONS_DEFINE=		OPENSSL

OPENSSL_DESC=		Enable HTTPS support using the HsOpenSSL library

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--flags="openssl"
USE_CABAL+=		HsOpenSSL>=0.10
.else
CONFIGURE_ARGS+=	--flags="-openssl"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
