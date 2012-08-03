# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.9.4.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	base64-bytestring>=0.1 blaze-html>=0.4.3.0 citeproc-hs>=0.3.4 \
		highlighting-kate>=0.5.1 HTTP>=4000.0.5 json>=0.4 mtl>=1.1 \
		network>=2 pandoc-types>=1.9.0.2 parsec>=3.1 random>=1 \
		syb>=0.1 tagsoup>=0.12.5 temporary>=1.1 texmath>=0.6.0.2 \
		utf8-string>=0.3 xml>=1.3.12 zip-archive>=0.1.1.7 \
		zlib>=0.5

MAN1=		pandoc.1
MAN5=		pandoc_markdown.5

OPTIONS_MULTI=		FORMAT
OPTIONS_MULTI_FORMAT=	EXECUTABLE LIBRARY
OPTIONS_DEFAULT=	EXECUTABLE LIBRARY

EXECUTABLE_DESC=	Build the pandoc executable
LIBRARY_DESC=		Build the pandoc library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="exectuable"
EXECUTABLE+=		pandoc
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.if ${PORT_OPTIONS:MLIBRARY}
CONFIGURE_ARGS+=	--flags="library"
.else
CONFIGURE_ARGS+=	--flags="-library"
STANDALONE=		yes
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
