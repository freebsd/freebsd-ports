# $FreeBSD$

PORTNAME=	citeproc-hs
PORTVERSION=	0.3.10
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Citation Style Language implementation in Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	json mtl pandoc-types>=1.8 parsec syb utf8-string xml

FLAGS_DEFINE=		BIBUTILS EMBED_DATA HEXPAT NETWORK UNICODE_COLLATION
FLAGS_DEFAULT=		BIBUTILS HEXPAT NETWORK

BIBUTILS_DESC=		Use Chris Putnam's Bibutils
BIBUTILS_FLAG_ENABLE=	bibutils
BIBUTILS_FLAG_CABAL=	hs-bibutils>=0.3

EMBED_DATA_DESC=	Embed locale files into the library
EMBED_DATA_FLAG_ENABLE=	embed_data_files
EMBED_DATA_FLAG_CABAL=	file-embed

HEXPAT_DESC=		Use hexpat to parse XML
HEXPAT_FLAG_ENABLE=	hexpat
HEXPAT_FLAG_CABAL=	hexpat>=0.20.2

NETWORK_DESC=		Use network and HTTP to retrieve CSL file
NETWORK_FLAG_ENABLE=	network
NETWORK_FLAG_CABAL=	HTTP>=4000.0.9 network>=2.6 network-uri>=2.6

UNICODE_COLLATION_DESC=		Use bindings to the ICU libraries
UNICODE_COLLATION_FLAG_ENABLE=	unicode_collation
UNICODE_COLLATION_FLAG_CABAL=	text text-icu

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
