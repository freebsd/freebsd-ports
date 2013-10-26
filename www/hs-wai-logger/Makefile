# $FreeBSD$

PORTNAME=	wai-logger
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Logging system for WAI

LICENSE=	BSD

USE_CABAL=	blaze-builder byteorder case-insensitive date-cache>=0.3 \
		fast-logger>=0.3 http-types network wai

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
