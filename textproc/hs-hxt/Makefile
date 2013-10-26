# $FreeBSD$

PORTNAME=	hxt
PORTVERSION=	9.3.1.1
PORTREVISION=	4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Collection of tools for processing XML with Haskell

LICENSE=	MIT

USE_CABAL=	HUnit>=1.2 hxt-charproperties>=9.1 hxt-regex-xmlschema>=9 \
		hxt-unicode>=9.0.1 mtl>=2 network>=2.1 parsec>=2.1

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
