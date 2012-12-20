# $FreeBSD$

PORTNAME=	html-conduit
PORTVERSION=	0.1.0.4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse HTML documents using xml-conduit datatypes

LICENSE=	MIT

CABAL_SETUP=	Setup.hs

USE_CABAL=	conduit>=0.5 filesystem-conduit>=0.5 resourcet>=0.3 \
		system-filepath>=0.4 tagstream-conduit>=0.4 text \
		transformers xml-conduit>=1.0 xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
