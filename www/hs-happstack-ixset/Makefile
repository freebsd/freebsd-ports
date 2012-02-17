# New ports collection makefile for: hs-happstack-ixset
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	happstack-ixset
PORTVERSION=	6.0.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Efficient relational queries on Haskell sets

LICENSE=	BSD
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs
USE_CABAL=	happstack-data>=6.0 happstack-util>=6.0 mtl>=1.1 \
		syb syb-with-class>=0.6.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
