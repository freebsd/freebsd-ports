# New ports collection makefile for: hs-pem
# Date created:        May 9, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pem
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Privacy Enhanced Mail (PEM) format reader and writer

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	attoparsec base64-bytestring cereal mtl

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
