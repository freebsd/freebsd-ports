# $FreeBSD$

PORTNAME=	regex-pcre-builtin
PORTVERSION=	0.94.4.5.8.31
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Replaces/Enhances Text.Regex

LICENSE=	BSD

USE_CABAL=	regex-base>=0.93

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
