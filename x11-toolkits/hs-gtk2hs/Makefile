# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk2hs
PORTVERSION=	0.13.2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	GTK2 Binding for Haskell

METAPORT=	yes
USE_CABAL=	glib gio cairo pango gtk

FLAGS_DEFINE=			GCONF GTKSOURCEVIEW2 SVGCAIRO VTE WEBKIT

GCONF_DESC=			GConf2 configuration system
GCONF_FLAG_CABAL=		gconf

GTKSOURCEVIEW2_DESC=		Source code editor
GTKSOURCEVIEW2_FLAG_CABAL=	gtksourceview2

SVGCAIRO_DESC=			Cairo SVG loader
SVGCAIRO_FLAG_CABAL=		svgcairo

VTE_DESC=			Terminal emulator
VTE_FLAG_CABAL=			vte

WEBKIT_DESC=			WebKit rendering engine
WEBKIT_FLAG_CABAL=		webkit

.include "../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
