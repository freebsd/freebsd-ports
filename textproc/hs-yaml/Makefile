# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	0.11.0.0
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Support for parsing and rendering YAML documents

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.5 attoparsec conduit>=1.1.0 enclosed-exceptions \
		libyaml resourcet>=0.3 scientific unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
