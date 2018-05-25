# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	0.13.5.0
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Pango text rendering engine

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	cairo>=0.13.0.0 glib>=0.13.0.0 mtl
USE_GNOME=	pango

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
