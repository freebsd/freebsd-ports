# $FreeBSD$

PORTNAME=	citeproc-hs
PORTVERSION=	0.3.8
PORTREVISION=	4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Citation Style Language implementation in Haskell

LICENSE=	BSD

USE_CABAL=	json mtl pandoc-types>=1.8 parsec syb utf8-string xml

OPTIONS_DEFINE=		BIBUTILS HEXPAT NETWORK
OPTIONS_DEFAULT=	BIBUTILS HEXPAT NETWORK

BIBUTILS_DESC=		Use Chris Putnam's Bibutils
HEXPAT_DESC=		Use hexpat to parse XML
NETWORK_DESC=		Use network and HTTP to retrieve CSL file

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MBIBUTILS}
CONFIGURE_ARGS+=	--flags="bibutils"
USE_CABAL+=		hs-bibutils>=0.3
.else
CONFIGURE_ARGS+=	--flags="-bibutils"
.endif

.if ${PORT_OPTIONS:MHEXPAT}
CONFIGURE_ARGS+=	--flags="hexpat"
USE_CABAL+=		hexpat>=0.20.2
.else
CONFIGURE_ARGS+=	--flags="-hexpat"
.endif

.if ${PORT_OPTIONS:MNETWORK}
CONFIGURE_ARGS+=	--flags="network"
USE_CABAL+=		HTTP>=4000.0.9 network>=2
.else
CONFIGURE_ARGS+=	--flags="-network"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
