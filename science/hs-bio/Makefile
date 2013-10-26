# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	bio
PORTVERSION=	0.5.2
PORTREVISION=	5
CATEGORIES=	science haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bioinformatics library

LICENSE=	LGPL21

USE_CABAL=	mtl parallel parsec QuickCheck>=2 tagsoup>=0.8

EXECUTABLE=	fastout flowclip flx frecover frename orf rselect-pe

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
