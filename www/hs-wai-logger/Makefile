# $FreeBSD$

PORTNAME=	wai-logger
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A logging system for WAI

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	blaze-builder byteorder case-insensitive date-cache>=0.3 \
		fast-logger>=0.3 http-types network wai

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
