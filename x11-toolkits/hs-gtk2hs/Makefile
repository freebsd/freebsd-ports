# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk2hs
PORTVERSION=	0.12.4
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	GTK2 Binding for Haskell

METAPORT=	yes
USE_CABAL=	glib gio cairo pango gtk

OPTIONS_DEFINE=		GCONF GLADE GSTREAMER GTKGLEXT GTKSOURCEVIEW2 SVGCAIRO VTE WEBKIT SOEGTK

GCONF_DESC=		GConf2 configuration system
GLADE_DESC=		libglade UI loader
GSTREAMER_DESC=		Media codec library
GTKGLEXT_DESC=		Gtk+ OpenGL extension
GTKSOURCEVIEW2_DESC=	Source code editor
SVGCAIRO_DESC=		Cairo SVG loader
VTE_DESC=		Terminal emulator
WEBKIT_DESC=		WebKit rendering engine
SOEGTK_DESC=		Examples for Haskell SoE

.include "../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MGCONF}
USE_CABAL+=		gconf
.endif

.if ${PORT_OPTIONS:MGLADE}
USE_CABAL+=		glade
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_CABAL+=		gstreamer
.endif

.if ${PORT_OPTIONS:MGTKGLEXT}
USE_CABAL+=		gtkglext
.endif

.if ${PORT_OPTIONS:MGSOURCEVIEW2}
USE_CABAL+=		gsourceview2
.endif

.if ${PORT_OPTIONS:MSVGCAIRO}
USE_CABAL+=		svgcairo
.endif

.if ${PORT_OPTIONS:MVTE}
USE_CABAL+=		vte
.endif

.if ${PORT_OPTIONS:MWEBKIT}
USE_CABAL+=		webkit
.endif

.if ${PORT_OPTIONS:MSOEGTK}
USE_CABAL+=		soegtk
.endif

.include "../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
