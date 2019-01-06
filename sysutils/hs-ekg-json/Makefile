# $FreeBSD$

PORTNAME=	ekg-json
PORTVERSION=	0.1.0.6
PORTREVISION=	2
CATEGORIES=	sysutils haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	JSON encoding of ekg metrics

LICENSE=	BSD3CLAUSE

BROKEN=		Doesn't build with newest Haskell libraries
EXPIRATION_DATE=31.01.2018

USE_CABAL=	aeson ekg-core>=0.1 unordered-containers

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
