# New ports collection makefile for: hs-network-conduit
# Date created:        April 8, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	network-conduit
PORTVERSION=	0.4.0.1
PORTREVISION=	1
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Stream socket data using conduits

LICENSE=	BSD

USE_CABAL=	conduit>=0.4 lifted-base>=0.1 monad-control>=0.3 \
		network>=2.3 transformers>=0.2.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
