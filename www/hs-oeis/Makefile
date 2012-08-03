# New ports collection makefile for: hs-oeis
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oeis
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell interface to the Online Encyclopedia of Integer Sequences

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	HTTP>=4000.0.2 network>=2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
