# New ports collection makefile for:	hs-csv
# Date created:		11 August 2011
# Whom:			Kaspars Bankovskis <kaspars@bankovskis.lv>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A CSV library for Haskell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CABAL_SETUP=	Setup.hs
USE_CABAL=	parsec

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
