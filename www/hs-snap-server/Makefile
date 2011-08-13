# New ports collection makefile for: hs-snap-server
# Date created:        September 19, 2010
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	snap-server
PORTVERSION=	0.5.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A fast, iteratee-based, epoll-enabled web server for the Snap Framework

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	attoparsec>=0.8.1 attoparsec-enumerator>=0.2.0.1 binary>=0.5 \
		blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2 \
		bytestring-nums case-insensitive>=0.2 directory-tree \
		enumerator>=0.4.13.1 MonadCatchIO-transformers>=0.2.1 mtl>=2 \
		murmur-hash>=0.1 network>=2.3 PSQueue>=1.1 snap-core>=0.5.2 \
		text>=0.11 transformers unix-compat>=0.2 utf8-string \
		vector>=0.7 vector-algorithms>=0.4

OPTIONS=	LIBEV    "Use libev"                                        off \
		GNUTLS   "Enable https support using the libgnutls library" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_LIBEV)
CONFIGURE_ARGS+=	--flags="libev"
USE_CABAL+=		hlibev
.else
CONFIGURE_ARGS+=	--flags="-libev"
.endif

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--flags="gnutls"
LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--flags="-gnutls"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
