# New ports collection makefile for: hs-hxt
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hxt
PORTVERSION=	9.1.6
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A collection of tools for processing XML with Haskell

LICENSE=	MIT

USE_CABAL=	binary>=0.5 deepseq>=1.1 HUnit>=1.2 hxt-charproperties>=9.1 \
		hxt-regex-xmlschema>=9 hxt-unicode>=9.0.1 network>=2.1 \
		parsec>=2.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
