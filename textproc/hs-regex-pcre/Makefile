# $FreeBSD$

PORTNAME=	regex-pcre
PORTVERSION=	0.94.4
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The PCRE backend to accompany regex-base

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_CABAL=	regex-base

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
