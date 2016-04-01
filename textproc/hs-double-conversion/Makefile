# $FreeBSD$

PORTNAME=	double-conversion
PORTVERSION=	2.0.1.0
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast conversion between double-precision floating-point and text

LICENSE=	BSD3CLAUSE

USE_CABAL=	text>=0.11.0.8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${PORT_OPTIONS:MPCLANG} || ${PORT_OPTIONS:MBCLANG}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-double-conversion.cabal
LIB_DEPENDS+=	libcxxrt.so:devel/libcxxrt
.endif

.include <bsd.port.mk>
