# New ports collection makefile for: hs-hscolour
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hscolour
PORTVERSION=	1.15
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	print haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	Colourise Haskell code

CABAL_SETUP=	Setup.hs

EXECUTABLE=	HsColour

PORTDATA=		*

.if defined(SLAVE)
GHC_CMD=	ghc
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
