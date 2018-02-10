# $FreeBSD$

PORTNAME=	pandoc-citeproc
PORTVERSION=	0.10.5.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Supports using pandoc with citeproc

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.7 aeson-pretty attoparsec data-default \
		mtl pandoc>=1.13 pandoc-types>=1.12.3 parsec rfc5051 \
		setenv>=0.1 split syb tagsoup text vector xml-conduit>=1.2 \
		yaml>=0.8.8.7

EXECUTABLE=	pandoc-citeproc

FLAGS_DEFINE=	BIBUTILS EMBED_DATA UNICODE_COLLATION
FLAGS_DEFAULT=	BIBUTILS

BIBUTILS_DESC=		Use Chris Putnam's Bibutils
BIBUTILS_FLAG_ENABLE=	bibutils
BIBUTILS_FLAG_CABAL=	hs-bibutils>=0.3

EMBED_DATA_DESC=	Embed locale files into the library
EMBED_DATA_FLAG_ENABLE=	embed_data_files

UNICODE_COLLATION_DESC=		Use bindings to the Internationl Components for Unicode libraries
UNICODE_COLLATION_FLAG_ENABLE=	unicode_collation
UNICODE_COLLATION_FLAG_CABAL=	text-icu

FLAGS_DISABLE=	test_citeproc debug

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
