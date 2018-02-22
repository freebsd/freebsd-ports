# Created by: mainland@apeiron.net
# $FreeBSD$

PORTNAME=	lhs2tex
PORTVERSION=	1.19
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Preprocessor for typesetting Haskell sources with LaTeX

LICENSE=	GPLv2

USE_CABAL=	mtl regex-compat
USE_TEX=	latex dvipsk

STANDALONE=	yes
EXECUTABLE=	lhs2TeX

MAN1PAGES=	lhs2TeX.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
