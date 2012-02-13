# New ports collection makefile for: hs-snap-server
# Date created:        September 19, 2010
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	snap-server
PORTVERSION=	0.7.0.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A fast, iteratee-based, epoll-enabled web server for the Snap Framework

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 binary>=0.5 \
		blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2 \
		bytestring-nums case-insensitive>=0.3 directory-tree>=0.10 \
		enumerator>=0.4.13.1 MonadCatchIO-transformers>=0.2.1 mtl>=2 \
		murmur-hash>=0.1 network>=2.3 PSQueue>=1.1 snap-core>=0.7 \
		text>=0.11 transformers>=0.2 unix-compat>=0.2 vector>=0.7 \
		vector-algorithms>=0.4

OPTIONS=	LIBEV    "Use libev"                                        off \
		OPENSSL  "Enable HTTPS support using the HsOpenSSL library" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_LIBEV)
CONFIGURE_ARGS+=	--flags="libev"
USE_CABAL+=		hlibev
.else
CONFIGURE_ARGS+=	--flags="-libev"
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=	--flags="openssl"
USE_CABAL+=		HsOpenSSL
.else
CONFIGURE_ARGS+=	--flags="-openssl"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
