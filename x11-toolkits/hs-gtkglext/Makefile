# $FreeBSD$

PORTNAME=	gtkglext
PORTVERSION=	0.12.5.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GTK+ OpenGL Extension

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	glib>=0.12.5.0 gtk>=0.12.5.0 mtl pango>=0.12.5.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
