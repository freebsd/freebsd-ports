# Created by: John MacFarlane <jgm@berkeley.edu>
# $FreeBSD$

PORTNAME=	pandoc
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

LIB_DEPENDS=	libffi.so:devel/libffi

USE_ALEX=	yes
USE_CABAL=	aeson aeson-pretty base64-bytestring blaze-html blaze-markup \
		cmark cmark-gfm data-default deepseq-generics doctemplates \
		extensible-exceptions filemanip Glob haddock-library hslua \
		hslua-module-text HsYAML http-client http-client-tls \
		http-types HTTP JuicyPixels mtl  network network-uri \
		pandoc-types random scientific SHA skylighting syb tagsoup \
		temporary texmath unicode-transforms unordered-containers \
		vector xml yaml zip-archive zlib
USE_HAPPY=	yes

FLAGS_DEFINE=		EMBED_DATA TRYPANDOC
OPTIONS_DEFINE=		PDFGEN
OPTIONS_DEFAULT=	PDFGEN

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_FLAG_ENABLE=	embed_data_files
EMBED_DATA_FLAG_CABAL=	file-embed>=0.0
PDFGEN_DESC=		Include TeX for PDF generation
PDFGEN_USE=		TEX=texmf:run
TRYPANDOC_DESC=		Build trypandoc cgi executable
TRYPANDOC_FLAG_ENABLE=	trypandoc
TRYPANDOC_FLAG_CABAL=	aeson wai-extra wai>=0.3
TRYPANDOC_FLAG_EXECUTABLE=	trypandoc

EXECUTABLE=	pandoc
FLAGS_ENABLE=	network-uri
FLAGS_DISABLE=	make-pandoc-man-pages
IGNORE_DYNAMIC=	yes
IGNORE_PROFILE=	yes
MAN1SRC=	man
MAN1PAGES=	pandoc.1
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
