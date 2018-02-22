# $FreeBSD$

PORTNAME=	gtk
PORTVERSION=	0.14.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Gtk+ graphical user interface library

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	cairo>=0.13.0.0 gio>=0.13.0 glib>=0.13.0.0 mtl \
		pango>=0.13.0.0 text>=0.11.0.6
USE_GNOME=	gtk20

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
