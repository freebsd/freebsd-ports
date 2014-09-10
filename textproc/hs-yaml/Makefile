# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	0.8.8.4
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Support for parsing and rendering YAML documents

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.5 attoparsec conduit>=1.0.11 resourcet>=0.3 \
		scientific text unordered-containers vector

EXECUTABLE=	yaml2json json2yaml

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
