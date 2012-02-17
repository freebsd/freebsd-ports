# New ports collection makefile for: hs-happstack-state
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	happstack-state
PORTVERSION=	6.1.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Event-based distributed state

LICENSE=	BSD
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs
USE_CABAL=	binary happstack-data>=6.0 happstack-util>=6.0 hslogger>=1.0.2 \
		mtl>=1.1 stm>=2.1.2.2 syb

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
