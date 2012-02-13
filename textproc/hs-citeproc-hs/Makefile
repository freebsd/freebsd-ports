# New ports collection makefile for: hs-citeproc-hs
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	citeproc-hs
PORTVERSION=	0.3.3
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Citation Style Language implementation in Haskell

LICENSE=	BSD

USE_CABAL=	json mtl pandoc-types>=1.8 utf8-string xml

OPTIONS=	BIBUTILS "Use Chris Putnam's Bibutils" on \
		NETWORK  "Use network and HTTP to retrieve CSL file" on

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_BIBUTILS)
CONFIGURE_ARGS+=	--flags="bibutils"
USE_CABAL+=		hs-bibutils>=0.3
.else
CONFIGURE_ARGS+=	--flags="-bibutils"
.endif

.if defined(WITH_NETWORK)
CONFIGURE_ARGS+=	--flags="network"
USE_CABAL+=		HTTP>=4000.0.9 network>=2
.else
CONFIGURE_ARGS+=	--flags="-network"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
