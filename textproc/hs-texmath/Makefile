# New ports collection makefile for: hs-texmath
# Date created:        January 10 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	texmath
PORTVERSION=	0.1.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion of LaTeX math formulas to MathML for Haskell

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	cgi json xml

EXECUTABLE=	testTeXMathML texmath-cgi

PORTDATA=		*

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
