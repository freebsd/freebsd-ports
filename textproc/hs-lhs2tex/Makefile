# Created by: mainland@apeiron.net
# $FreeBSD$

PORTNAME=	lhs2tex
PORTVERSION=	1.18.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Preprocessor for typesetting Haskell sources with LaTeX

LICENSE=	GPLv2

CABAL_SETUP=	Setup.hs
USE_CABAL=	mtl regex-compat

BUILD_DEPENDS+=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	mktexlsr:${PORTSDIR}/print/teTeX-base

STANDALONE=	yes
EXECUTABLE=	lhs2TeX

MAN1=		lhs2TeX.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
