# Created by: John MacFarlane <jgm@berkeley.edu>
# $FreeBSD$

PORTNAME=	pandoc
PORTVERSION=	1.12.4.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USE_CABAL=	aeson>=0.7 attoparsec>=0.10 base64-bytestring>=0.1 \
		blaze-html>=0.5 blaze-markup>=0.5.1 data-default>=0.4 \
		extensible-exceptions>=0.1 highlighting-kate>=0.5.8 \
		hslua>=0.3 HTTP>=4000.0.5 http-conduit>=1.9 http-types>=0.8 \
		mtl>=1.1 network>=2 pandoc-types>=1.12.3.3 parsec>=3.1 \
		random>=1 scientific>=0.2 syb>=0.1 tagsoup>=0.13.1 \
		temporary>=1.1 texmath>=0.6.6.1 text>=0.11 \
		unordered-containers>=0.2 vector>=0.10 xml>=1.3.12 \
		yaml>=0.8.8.2 zip-archive>=0.1.3.3 zlib>=0.5
USE_ALEX=	yes
USE_HAPPY=	yes

EXECUTABLE=	pandoc

# For PDF generation
USE_TEX=	texmf:run

MAN1PAGES=	pandoc.1
MAN5PAGES=	pandoc_markdown.5

FLAGS_DEFINE=			EMBED_DATA_FILES HTTP_CONDUIT
FLAGS_DEFAULT=			HTTP_CONDUIT

EMBED_DATA_FILES_DESC=		Embed data files in binary for relocatable executable
EMBED_DATA_FILES_FLAG_ENABLE=	embed_data_files

HTTP_CONDUIT_DESC=		Enable downloading of resources over HTTPS
HTTP_CONDUIT_FLAG_ENABLE=	http-conduit
HTTP_CONDUIT_FLAG_CABAL=	http-conduit>=1.9 http-types>=0.8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
