# $FreeBSD$

PORTNAME=	xml-conduit
PORTVERSION=	1.1.0.3
PORTREVISION=	4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pure-Haskell utilities for dealing with XML with the conduit package

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10 attoparsec-conduit>=1.0 blaze-builder>=0.2 \
		blaze-builder-conduit>=1.0 blaze-html>=0.5 blaze-markup>=0.5 \
		conduit>=1.0 data-default failure>=0.1 monad-control>=0.3 \
		resourcet>=0.3 system-filepath>=0.4 text>=0.7 \
		transformers>=0.2 xml-types>=0.3.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
