# New ports collection makefile for: hs-texmath
# Date created:        January 10 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	texmath
PORTVERSION=	0.5.0.4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion of LaTeX math formulas to MathML for Haskell

LICENSE=	GPLv2

CABAL_SETUP=	Setup.hs

USE_CABAL=	parsec>=2 syb xml

OPTIONS=	CGI	"Compile CGI executable"	off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_CGI)
CONFIGURE_ARGS+=	--flags="cgi"
USE_CABAL+=		cgi json utf8-string
EXECUTABLE+=		texmath-cgi
.else
CONFIGURE_ARGS+=	--flags="-cgi"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
