# $FreeBSD$

PORTNAME=	html-conduit
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse HTML documents using xml-conduit datatypes

LICENSE=	MIT

USE_CABAL=	conduit>=1.0 filesystem-conduit>=1.0 resourcet>=0.3 \
		system-filepath>=0.4 tagstream-conduit>=0.4 text \
		transformers xml-conduit>=1.1 xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
