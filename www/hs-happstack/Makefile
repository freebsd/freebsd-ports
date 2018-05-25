# $FreeBSD$

PORTNAME=	happstack
PORTVERSION=	7.0.2
PORTREVISION=	4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The haskell application server stack + code generation

LICENSE=	BSD3CLAUSE

USE_CABAL=	happstack-server>=7.0

IGNORE=		Doesn't build with recent GHC version

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
