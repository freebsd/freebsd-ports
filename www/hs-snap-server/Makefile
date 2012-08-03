# New ports collection makefile for: hs-snap-server
# Date created:        September 19, 2010
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	snap-server
PORTVERSION=	0.9.0
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A fast, iteratee-based, epoll-enabled web server for the Snap Framework

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 \
		blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2.0 \
		bytestring-nums case-insensitive>=0.3 directory-tree>=0.10 \
		enumerator>=0.4.15 MonadCatchIO-transformers>=0.2.1 \
		mtl>=2 murmur-hash>=0.1 network>=2.3 snap-core>=0.9 \
		text>=0.11 transformers>=0.2 unix-compat>=0.2 vector>=0.7 \
		vector-algorithms>=0.4

OPTIONS_DEFINE=		LIBEV OPENSSL

LIBEV_DESC=		Use libev
OPENSSL_DESC=		Enable HTTPS support using the HsOpenSSL library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBEV}
CONFIGURE_ARGS+=	--flags="libev"
USE_CABAL+=		hlibev
.else
CONFIGURE_ARGS+=	--flags="-libev"
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--flags="openssl"
USE_CABAL+=		HsOpenSSL
.else
CONFIGURE_ARGS+=	--flags="-openssl"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
