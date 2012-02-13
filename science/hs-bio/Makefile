# New ports collection makefile for: hs-bio
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bio
PORTVERSION=	0.5.1
CATEGORIES=	science haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell bioinformatics library

LICENSE=	LGPL21

CABAL_SETUP=	Setup.hs
USE_CABAL=	binary>=0.4 mtl parallel parsec QuickCheck>=2 tagsoup>=0.8

EXECUTABLE=	fastout flx frecover frename flowclip orf rselect-pe

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
