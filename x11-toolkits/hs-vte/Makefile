# $FreeBSD$

PORTNAME=	vte
PORTVERSION=	0.12.5.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the VTE library

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	glib>=0.12.5.0 gtk>=0.12.5.0 mtl pango>=0.12.5.0
USE_GNOME=	vte

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
