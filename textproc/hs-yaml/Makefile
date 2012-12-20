# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	0.8.1.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Low-level binding to the libyaml C library

LICENSE=	BSD

USE_CABAL=	aeson>=0.5 attoparsec conduit>=0.5 resourcet>=0.3 text \
		transformers>=0.1 unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
