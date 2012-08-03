# New ports collection makefile for:	hs-HsOpenSSL
# Date created:		November 19, 2011
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	HsOpenSSL
PORTVERSION=	0.10.3.2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	(Incomplete) OpenSSL binding for Haskell

FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	network>=2.1.0.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
