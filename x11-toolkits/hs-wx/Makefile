# $FreeBSD$

PORTNAME=	wx
PORTVERSION=	0.92.3.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	wxHaskell

USES=		dos2unix
USE_CABAL=	stm wxcore>=0.91
DOS2UNIX_FILES=	src/Graphics/UI/WX/Window.hs

USE_WX=		3.0
WX_COMPS=	wx

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
