# New ports collection makefile for:   gtk2hs
# Date created:        03 June 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk2hs
PORTVERSION=	0.12.2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GTK2 Binding for Haskell

METAPORT=	yes
USE_CABAL=	glib gio cairo pango gtk

OPTIONS=	GCONF          "GConf2 configuration system" off \
		GLADE          "libglade UI loader"          off \
		GSTREAMER      "Media codec library"         off \
		GTKGLEXT       "Gtk+ OpenGL extension"       off \
		GTKSOURCEVIEW2 "Source code editor"          off \
		SVGCAIRO       "Cairo SVG loader"            off \
		VTE            "Terminal emulator"           off \
		WEBKIT         "WebKit rendering engine"     off \
		SOEGTK         "Examples for Haskell SoE"    off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_GCONF)
USE_CABAL+=		gconf
.endif

.if defined(WITH_GLADE)
USE_CABAL+=		glade
.endif

.if defined(WITH_GSTREAMER)
USE_CABAL+=		gstreamer
.endif

.if defined(WITH_GTKGLEXT)
USE_CABAL+=		gtkglext
.endif

.if defined(WITH_GSOURCEVIEW2)
USE_CABAL+=		gsourceview2
.endif

.if defined(WITH_SVGCAIRO)
USE_CABAL+=		svgcairo
.endif

.if defined(WITH_VTE)
USE_CABAL+=		vte
.endif

.if defined(WITH_WEBKIT)
USE_CABAL+=		webkit
.endif

.if defined(WITH_SOEGTK)
USE_CABAL+=		soegtk
.endif

.include "../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
