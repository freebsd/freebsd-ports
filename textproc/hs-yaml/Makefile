# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	0.8.23.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Support for parsing and rendering YAML documents

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.5 attoparsec conduit>=1.1.0 enclosed-exceptions \
		resourcet>=0.3 scientific text unordered-containers vector

EXECUTABLE=	json2yaml yaml2json

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
