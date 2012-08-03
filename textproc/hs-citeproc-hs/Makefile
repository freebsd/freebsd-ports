# New ports collection makefile for: hs-citeproc-hs
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	citeproc-hs
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Citation Style Language implementation in Haskell

LICENSE=	BSD

USE_CABAL=	json mtl pandoc-types>=1.8 utf8-string xml

OPTIONS_DEFINE=		BIBUTILS NETWORK
OPTIONS_DEFAULT=	BIBUTILS NETWORK

BIBUTILS_DESC=		Use Chris Putnam's Bibutils
NETWORK_DESC=		Use network and HTTP to retrieve CSL file

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBIBUTILS}
CONFIGURE_ARGS+=	--flags="bibutils"
USE_CABAL+=		hs-bibutils>=0.3
.else
CONFIGURE_ARGS+=	--flags="-bibutils"
.endif

.if ${PORT_OPTIONS:MNETWORK}
CONFIGURE_ARGS+=	--flags="network"
USE_CABAL+=		HTTP>=4000.0.9 network>=2
.else
CONFIGURE_ARGS+=	--flags="-network"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
