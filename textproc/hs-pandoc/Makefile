# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.9.3
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	base64-bytestring>=0.1 blaze-html>=0.4.3.0 citeproc-hs>=0.3.4 \
		highlighting-kate>=0.5.0.2 HTTP>=4000.0.5 json>=0.4 \
		mtl>=1.1 network>=2 pandoc-types>=1.9.0.2 parsec>=3.1 \
		random>=1 syb>=0.1 tagsoup>=0.12.5 temporary>=1.1 \
		texmath>=0.6.0.2 utf8-string>=0.3 xml>=1.3.12 \
		zip-archive>=0.1.1.7 zlib>=0.5

MAN1=		pandoc.1
MAN5=		pandoc_markdown.5

OPTIONS=	EXECUTABLE   "Build the pandoc executable" on \
		LIBRARY      "Build the pandoc library" on \

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="exectuable"
EXECUTABLE+=		pandoc
.else
CONFIGURE_ARGS+=	--flags="-executable"
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

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
