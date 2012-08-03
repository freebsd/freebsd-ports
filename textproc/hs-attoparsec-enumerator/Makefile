# New ports collection makefile for: hs-attoparsec-enumerator
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	attoparsec-enumerator
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pass input from an enumerator to an Attoparsec parser

LICENSE=	MIT
FILE_LICENSE=	license.txt

CABAL_SETUP=	Setup.hs
USE_CABAL=	attoparsec>=0.10 enumerator>=0.4 text

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
