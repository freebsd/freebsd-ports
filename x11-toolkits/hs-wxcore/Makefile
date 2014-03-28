# $FreeBSD$

PORTNAME=	wxcore
PORTVERSION=	0.90.0.3
PORTREVISION=	7
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	wxHaskell core

USE_CABAL=	parsec stm wxc>=0.90.0.4 wxdirect>=0.90

BROKEN=		does not build with any of the supported wx

USE_WX=		3.0
WX_COMPS=	wx
WX_UNICODE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
