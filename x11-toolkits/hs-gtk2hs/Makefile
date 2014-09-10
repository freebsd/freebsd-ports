# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk2hs
PORTVERSION=	0.12.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	GTK2 Binding for Haskell

METAPORT=	yes
USE_CABAL=	glib gio cairo pango gtk

FLAGS_DEFINE=			GCONF GLADE GSTREAMER GTKGLEXT GTKSOURCEVIEW2 SVGCAIRO VTE WEBKIT SOEGTK

GCONF_DESC=			GConf2 configuration system
GCONF_FLAG_CABAL=		gconf

GLADE_DESC=			libglade UI loader
GLADE_FLAG_CABAL=		glade

GSTREAMER_DESC=			Media codec library
GSTREAMER_FLAG_CABAL=		gstreamer

GTKGLEXT_DESC=			Gtk+ OpenGL extension
GTKGLEXT_FLAG_CABAL=		gtkglext

GTKSOURCEVIEW2_DESC=		Source code editor
GTKSOURCEVIEW2_FLAG_CABAL=	gtksourceview2

SVGCAIRO_DESC=			Cairo SVG loader
SVGCAIRO_FLAG_CABAL=		svgcairo

VTE_DESC=			Terminal emulator
VTE_FLAG_CABAL=			vte

WEBKIT_DESC=			WebKit rendering engine
WEBKIT_FLAG_CABAL=		webkit

SOEGTK_DESC=			Examples for Haskell SoE
SOEGTK_FLAG_CABAL=		soegtk

.include "../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
