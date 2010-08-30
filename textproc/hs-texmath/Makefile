# New ports collection makefile for: hs-texmath
# Date created:        January 10 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	texmath
PORTVERSION=	0.3.0.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion of LaTeX math formulas to MathML for Haskell

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	xml utf8-string

OPTIONS=	CGI	"Compile CGI executable"	off \
		TEST	"Compile test executable"	off

PORTDATA=		*

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_CGI)
CONFIGURE_ARGS+=	--flags="cgi"
USE_HACKAGE+=		cgi json
EXECUTABLE+=		texmath-cgi
PLIST_SUB+=		MAYBE_CGI=""
.else
CONFIGURE_ARGS+=	--flags="-cgi"
PLIST_SUB+=		MAYBE_CGI="@comment "
.endif

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="test"
EXECUTABLE+=		testTeXMathML
PLIST_SUB+=		MAYBE_TEST=""
.else
CONFIGURE_ARGS+=	--flags="-test"
PLIST_SUB+=		MAYBE_TEST="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
