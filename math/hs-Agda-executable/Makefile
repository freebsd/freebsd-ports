# New ports collection makefile for: hs-Agda-executable
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda-executable
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	Command-line program for type-checking and compiling Agda programs

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	Agda>=2.2.6

USE_ICONV=	yes

EXECUTABLE=	agda
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
