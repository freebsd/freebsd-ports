# New ports collection makefile for: hs-simple-sendfile
# Date created:        July 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	simple-sendfile
PORTVERSION=	0.2.0
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform library for the sendfile() system call

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	enumerator network transformers

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
