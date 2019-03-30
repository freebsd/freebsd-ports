# $FreeBSD$

PORTNAME=	adjunctions
PORTVERSION=	4.4
PORTREVISION=	3
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Adjunctions and representable functors

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	comonad>=4 distributive>=0.4 free>=4.0 \
		mtl>=2.0.1 profunctors>=4 semigroupoids>=4 semigroups>=0.11 \
		tagged>=0.7 void>=0.5.5.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
