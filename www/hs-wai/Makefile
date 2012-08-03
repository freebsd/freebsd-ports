# New ports collection makefile for: hs-wai
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wai
PORTVERSION=	1.2.0.3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web Application Interface

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.2.1.4 conduit>=0.4 http-types>=0.6 \
		network>=2.2.1.5 text>=0.7 transformers>=0.2.2 vault>=0.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
