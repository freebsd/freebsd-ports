# Created by: John MacFarlane <jgm@berkeley.edu>
# $FreeBSD$

PORTNAME=	pandoc
PORTVERSION=	1.19.2.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USE_CABAL=	aeson base64-bytestring blaze-html \
		blaze-markup cmark data-default \
		deepseq-generics doctemplates extensible-exceptions  \
		filemanip haddock-library highlighting-kate \
		hslua HTTP JuicyPixels mtl  \
		network network-uri pandoc-types parsec \
		random scientific SHA skylighting syb tagsoup\
		temporary texmath text \
		unordered-containers vector xml \
		yaml zip-archive zlib

USE_ALEX=	yes
USE_HAPPY=	yes

EXECUTABLE=	pandoc

MAN1SRC=	man
MAN1PAGES=	pandoc.1

OPTIONS_DEFINE=		PDFGEN
OPTIONS_DEFAULT=	PDFGEN

PDFGEN_DESC=	Include TeX for PDF generation
PDFGEN_USE=	TEX=texmf:run

FLAGS_DEFINE=			EMBED_DATA HTTPS TRYPANDOC
FLAGS_DEFAULT=			HTTPS

EMBED_DATA_DESC=		Embed data files in binary for relocatable executable
EMBED_DATA_FLAG_ENABLE=	embed_data_files
EMBED_DATA_FLAG_CABAL=	hsb2hs>=0.3.1

HTTPS_DESC=		Enable downloading of resources over HTTPS
HTTPS_FLAG_ENABLE=	https
HTTPS_FLAG_CABAL=	http-client>=0.3.2 http-client-tls>=0.2 http-types>=0.8

TRYPANDOC_DESC=			Build trypandoc cgi executable
TRYPANDOC_FLAG_ENABLE=		trypandoc
TRYPANDOC_FLAG_CABAL=		aeson highlighting-kate text wai-extra wai>=0.3 \
				http-types
TRYPANDOC_FLAG_EXECUTABLE=	trypandoc

FLAGS_ENABLE=		network-uri
FLAGS_DISABLE=		make-pandoc-man-pages

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
