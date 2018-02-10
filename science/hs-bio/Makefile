# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	bio
PORTVERSION=	0.5.3
PORTREVISION=	4
CATEGORIES=	science haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bioinformatics library

LICENSE=	LGPL21

USE_CABAL=	mtl old-time parallel parsec QuickCheck>=2 random tagsoup>=0.8

EXECUTABLE=	fastout flowclip flx frecover frename orf rselect-pe

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
