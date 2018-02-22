# $FreeBSD$

PORTNAME=	ekg
PORTVERSION=	0.4.0.13
PORTREVISION=	1
CATEGORIES=	sysutils haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Remote monitoring of processes

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson ekg-core>=0.1 ekg-json>=0.1 network snap-core \
		snap-server text unordered-containers

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
