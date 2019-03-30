# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	math-functions
PORTVERSION=	0.3.1.0
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Special functions and Chebyshev polynomials

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	data-default-class primitive vector vector-th-unbox

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
