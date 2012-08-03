# New ports collection makefile for: hs-http-types
# Date created:        May 24, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	http-types
PORTVERSION=	0.6.11
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Generic HTTP types for Haskell (for both client and server code)

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	blaze-builder>=0.2.1.4 case-insensitive>=0.2 text>=0.11.0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
