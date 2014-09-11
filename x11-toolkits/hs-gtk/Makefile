# $FreeBSD$

PORTNAME=	gtk
PORTVERSION=	0.12.5.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Gtk+ graphical user interface library

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	cairo>=0.12.5.3 gio>=0.12.5 glib>=0.12.5.4 mtl pango>=0.12.5.3
USE_GNOME=	gtk20

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
