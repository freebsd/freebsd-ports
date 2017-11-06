# $FreeBSD$

PORTNAME=	shelly
PORTVERSION=	1.6.8.3
CATEGORIES=	shells haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Shell-like (systems) programming in Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	async enclosed-exceptions exceptions>=0.6 lifted-async \
		lifted-base monad-control>=0.3.2 mtl>=2 system-fileio \
		system-filepath>=0.4.7 text transformers-base unix-compat

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
