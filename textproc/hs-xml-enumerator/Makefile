# New ports collection makefile for: hs-xml-enumerator
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xml-enumerator
PORTVERSION=	0.4.4.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pure utilities for dealing with XML with the enumerator

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 blaze-builder>=0.2 \
		blaze-builder-enumerator>=0.2 data-default>=0.2 \
		enumerator>=0.4.5 failure>=0.1 text>=0.7 transformers>=0.2 \
		xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
