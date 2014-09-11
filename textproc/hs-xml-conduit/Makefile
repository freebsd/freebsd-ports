# $FreeBSD$

PORTNAME=	xml-conduit
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Pure-Haskell utilities for dealing with XML with the conduit package

LICENSE=	BSD3CLAUSE

USE_CABAL=	attoparsec>=0.10 blaze-builder>=0.2 blaze-html>=0.5 \
		blaze-markup>=0.5 conduit>=1.0 conduit-extra data-default \
		monad-control>=0.3 resourcet>=0.3 system-filepath>=0.4 \
		text>=0.7 xml-types>=0.3.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
