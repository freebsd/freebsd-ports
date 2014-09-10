# Created by: John MacFarlane <jgm@berkeley.edu>
# $FreeBSD$

PORTNAME=	pandoc
PORTVERSION=	1.13.0.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USE_CABAL=	aeson>=0.7 attoparsec>=0.10 base64-bytestring>=0.1 \
		blaze-html>=0.5 blaze-markup>=0.5.1 data-default>=0.4 \
		extensible-exceptions>=0.1 haddock-library>=1.1 \
		highlighting-kate>=0.5.8 hslua>=0.3 HTTP>=4000.0.5 \
		JuicyPixels>=3.1.6.1 mtl>=1.1 network>=2 \
		pandoc-types>=1.12.3.3 parsec>=3.1 random>=1 scientific>=0.2 \
		SHA>=1.6 syb>=0.1 tagsoup>=0.13.1 temporary>=1.1 texmath>=0.8 \
		text>=0.11 unordered-containers>=0.2 vector>=0.10 xml>=1.3.12 \
		yaml>=0.8.8.2 zip-archive>=0.2.3.4 zlib>=0.5

USE_ALEX=	yes
USE_HAPPY=	yes

EXECUTABLE=	pandoc

# For PDF generation
USE_TEX=	texmf:run

MAN1SRC=	man/man1
MAN5SRC=	man/man5
MAN1PAGES=	pandoc.1
MAN5PAGES=	pandoc_markdown.5
MANCOMPRESSED=	no

FLAGS_DEFINE=			EMBED_DATA_FILES HTTPS TRYPANDOC
FLAGS_DEFAULT=			HTTPS

EMBED_DATA_FILES_DESC=		Embed data files in binary for relocatable executable
EMBED_DATA_FILES_FLAG_ENABLE=	embed_data_files

HTTPS_DESC=		Enable downloading of resources over HTTPS
HTTPS_FLAG_ENABLE=	https
HTTPS_FLAG_CABAL=	http-client>=0.3.2 http-client-tls>=0.2 http-types>=0.8

TRYPANDOC_DESC=			Build trypandoc cgi executable
TRYPANDOC_FLAG_ENABLE=		trypandoc
TRYPANDOC_FLAG_CABAL=		aeson highlighting-kate text wai-extra wai>=0.3 \
				http-types
TRYPANDOC_FLAG_EXECUTABLE=	trypandoc

FLAGS_DISABLE=		make-pandoc-man-pages

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
