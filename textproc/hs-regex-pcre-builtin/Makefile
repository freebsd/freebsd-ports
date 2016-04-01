# $FreeBSD$

PORTNAME=	regex-pcre-builtin
PORTVERSION=	0.94.4.8.8.35
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Replaces/Enhances Text.Regex

LICENSE=	BSD3CLAUSE

USE_CABAL=	regex-base>=0.93

LIB_DEPENDS=	libpcre.so:devel/pcre

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
