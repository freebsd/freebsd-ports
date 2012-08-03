# New ports collection makefile for:	hs-math-functions
# Date created:				Feb 2, 2012
# Whom:					Wen Heping<wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	math-functions
PORTVERSION=	0.1.1.1
PORTREVISION=	2
CATEGORIES=	math haskell

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Special mathematical functions and Chebyshev polynomials

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	erf>=2 vector>=0.7

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
