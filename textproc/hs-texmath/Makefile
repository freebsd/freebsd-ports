# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	texmath
PORTVERSION=	0.11.1.2
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between formats used to represent mathematics

LICENSE=	GPLv2

USE_CABAL=	aeson mtl network network-uri pandoc-types split syb xml

FLAGS_ENABLE=	network-uri
FLAGS_DISABLE=	executable

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
