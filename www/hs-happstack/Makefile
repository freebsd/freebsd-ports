# New ports collection makefile for: hs-happstack
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	happstack
PORTVERSION=	6.0.6
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The haskell application server stack + code generation

LICENSE=	BSD
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	happstack-data>=6.0 happstack-ixset>=6.0 happstack-server>=6.0 \
		happstack-state>=6.0 happstack-util>=6.0 syb

EXECUTABLE=	happstack

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
