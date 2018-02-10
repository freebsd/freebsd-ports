# $FreeBSD$

PORTNAME=	hexpat
PORTVERSION=	0.20.13
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	XML parser/formatter based on expat

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libexpat.so:textproc/expat2

USE_CABAL=	List>=0.4.2 text>=0.5.0.0 utf8-string>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
