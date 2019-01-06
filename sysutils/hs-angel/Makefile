# $FreeBSD$

PORTNAME=	angel
PORTVERSION=	0.6.2
PORTREVISION=	6
CATEGORIES=	sysutils haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Process management and supervision daemon

LICENSE=	BSD3CLAUSE

DEPRECATED=	No releases since 2016
BROKEN=		Doesn't build with recent GHC
EXPIRATION_DATE=31.01.2019

USE_CABAL=	configurator>=0.1 mtl old-locale optparse-applicative \
		unordered-containers>=0.1.4

EXECUTABLE=	angel

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
