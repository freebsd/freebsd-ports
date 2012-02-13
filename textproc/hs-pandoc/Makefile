# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.8.2.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A general markup converter

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs
USE_CABAL=	base64-bytestring>=0.1 citeproc-hs>=0.3.1 dlist>=0.4 \
		HTTP>=4000.0.5 json>=0.4 mtl>=1.1 network>=2 pandoc-types>=1.8 \
		parsec>=2.1 tagsoup>=0.12 texmath>=0.5 utf8-string>=0.3 \
		xhtml>=3000.0 xml>=1.3.5 zip-archive>=0.1.1.7

MAN1=		pandoc.1 markdown2pdf.1
MAN5=		pandoc_markdown.5

OPTIONS=	HIGHLIGHTING "Compile in support for syntax highlighting" off \
		EXECUTABLE   "Build the pandoc executable" on \
		WRAPPERS     "Build the wrappers (markdown2pdf)" on \
		LIBRARY      "Build the pandoc library" on \
		THREADED     "Compile markdown2pdf with -threaded option" on

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_HIGHLIGHTING)
CONFIGURE_ARGS+=	--flags="highlighting"
USE_CABAL+=		highlighting-kate
.else
CONFIGURE_ARGS+=	--flags="-highlighting"
.endif

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="exectuable"
EXECUTABLE+=		pandoc
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.if defined(WITH_WRAPPERS)
CONFIGURE_ARGS+=	--flags="wrappers"
EXECUTABLE+=		markdown2pdf

.if !defined(WITH_EXECUTABLE)
IGNORE=		cannot be compiled since wrappers require an executable.  Please (re)run 'make config' and choose EXECUTABLE
.endif

.else
CONFIGURE_ARGS+=	--flags="-wrappers"
.endif

.if defined(WITH_LIBRARY)
CONFIGURE_ARGS+=	--flags="library"
.else
CONFIGURE_ARGS+=	--flags="-library"
STANDALONE=		yes
.endif

.if !defined(WITH_EXECUTABLE) && !defined(WITH_LIBRARY)
IGNORE=		cannot be compiled in this configuration.  Please (re)run 'make config' and choose either EXECUTABLE or LIBRARY or both
.endif

.if defined(WITH_THREADED)
CONFIGURE_ARGS+=	--flags="threaded"
.else
CONFIGURE_ARGS+=	--flags="-threaded"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
