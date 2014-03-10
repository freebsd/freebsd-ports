# Created by: John MacFarlane <jgm@berkeley.edu>
# $FreeBSD$

PORTNAME=	pandoc
PORTVERSION=	1.11.1
PORTREVISION=	5
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2

USE_CABAL=	base64-bytestring>=0.1 blaze-html>=0.6 blaze-markup>=0.5.1 \
		citeproc-hs>=0.3.7 data-default>=0.4 highlighting-kate>=0.5.3.7 \
		HTTP>=4000.0.5 json>=0.4 mtl>=1.1 network>=2 \
		pandoc-types>=1.10 parsec>=3.1 random>=1 syb>=0.1 \
		tagsoup>=0.12.5 temporary>=1.1 texmath>=0.6.1.3 \
		text>=0.11 xml>=1.3.12 zip-archive>=0.1.3.3 zlib>=0.5

EXECUTABLE=	pandoc

# For PDF generation
RUN_DEPENDS+=	latex-ifluatex>=1.3:${PORTSDIR}/print/latex-ifluatex \
		ifxetex>=0:${PORTSDIR}/print/ifxetex

MAN1=		pandoc.1
MAN5=		pandoc_markdown.5

OPTIONS_DEFINE=		EMBED_DATA_FILES

EMBED_DATA_FILES_DESC=	Embed data files in binary for relocatable executable

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEMBED_DATA_FILES}
CONFIGURE_ARGS+=	--flags="embed_data_files"
.else
CONFIGURE_ARGS+=	--flags="-embed_data_files"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
