# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	HaXml
PORTVERSION=	1.20.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A collection of utilities for using Haskell and XML together

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	polyparse>=1.2

EXECUTABLE=	Canonicalise CanonicaliseLazy \
		DtdToHaskell MkOneOf Validate \
		Xtract XtractLazy

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
