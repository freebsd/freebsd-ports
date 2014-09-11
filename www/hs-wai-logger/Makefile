# $FreeBSD$

PORTNAME=	wai-logger
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Logging system for WAI

LICENSE=	BSD3CLAUSE

USE_CABAL=	auto-update blaze-builder byteorder case-insensitive \
		fast-logger>=2.2 http-types network unix-time>=0.2.2 \
		wai>=2.0.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
