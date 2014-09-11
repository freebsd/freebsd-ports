# $FreeBSD$

PORTNAME=	citeproc-hs
PORTVERSION=	0.3.9
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Citation Style Language implementation in Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	json mtl pandoc-types>=1.8 parsec syb utf8-string xml

FLAGS_DEFINE=		BIBUTILS HEXPAT NETWORK UNICODE_COLLATION
FLAGS_DEFAULT=		BIBUTILS HEXPAT NETWORK

BIBUTILS_DESC=		Use Chris Putnam's Bibutils
BIBUTILS_FLAG_ENABLE=	bibutils
BIBUTILS_FLAG_CABAL=	hs-bibutils>=0.3

HEXPAT_DESC=		Use hexpat to parse XML
HEXPAT_FLAG_ENABLE=	hexpat
HEXPAT_FLAG_CABAL=	hexpat>=0.20.2

NETWORK_DESC=		Use network and HTTP to retrieve CSL file
NETWORK_FLAG_ENABLE=	network
NETWORK_FLAG_CABAL=	HTTP>=4000.0.9 network>=2

UNICODE_COLLATION_DESC=		Use bindings to the ICU libraries
UNICODE_COLLATION_FLAG_ENABLE=	unicode_collation
UNICODE_COLLATION_FLAG_CABAL=	text text-icu

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
