# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.5.1.1
CATEGORIES=	textproc haskell
PKGNAMEPREFIX=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A general markup converter

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	utf8-string>=0.3 zip-archive>=0.1.1.4 xml>=1.3.5 texmath HTTP>=4000.0.5

MAN1=		pandoc.1 markdown2pdf.1

PORTDATA=	*

OPTIONS=	HIGHLIGHTING "Compile in support for syntax highlighting" off \
		EXECUTABLE   "Build the pandoc executable" on \
		WRAPPERS     "Build the wrappers (markdown2pdf)" on \
		LIBRARY      "Build the pandoc library" on \
		CITEPROC     "Compile in support for citeproc-hs" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_HIGHLIGHTING)
CONFIGURE_ARGS+=	--flags="highlighting"
USE_HACKAGE+=		highlighting-kate
.else
CONFIGURE_ARGS+=	--flags="-highlighting"
.endif

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="exectuable"
EXECUTABLE+=		pandoc
PLIST_SUB+=		MAYBE_EXECUTABLE=""
.else
CONFIGURE_ARGS+=	--flags="-executable"
PLIST_SUB+=		MAYBE_EXECUTABLE="@comment "
.endif

.if defined(WITH_WRAPPERS)
CONFIGURE_ARGS+=	--flags="wrappers"
EXECUTABLE+=		markdown2pdf
PLIST_SUB+=		MAYBE_WRAPPERS=""

.if !defined(WITH_EXECUTABLE)
IGNORE=		cannot be compiled since wrappers require an executable.  Please (re)run 'make config' and choose EXECUTABLE
.endif

.else
CONFIGURE_ARGS+=	--flags="-wrappers"
PLIST_SUB+=		MAYBE_WRAPPERS="@comment "
.endif

.if defined(WITH_LIBRARY)
CONFIGURE_ARGS+=	--flags="library"
PLIST_SUB+=		MAYBE_LIBRARY=""
.else
CONFIGURE_ARGS+=	--flags="-library"
PLIST_SUB+=		MAYBE_LIBRARY="@comment "
STANDALONE=		yes
.endif

.if !defined(WITH_EXECUTABLE) && !defined(WITH_LIBRARY)
IGNORE=		cannot be compiled in this configuration.  Please (re)run 'make config' and choose either EXECUTABLE or LIBRARY or both
.endif

.if defined(WITH_CITEPROC)
CONFIGURE_ARGS+=	--flags="citeproc"
USE_HACKAGE+=		citeproc-hs
PLIST_SUB+=		MAYBE_CITEPROC=""
.else
CONFIGURE_ARGS+=	--flags="-citeproc"
PLIST_SUB+=		MAYBE_CITEPROC="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
