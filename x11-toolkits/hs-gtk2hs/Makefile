# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk2hs
PORTVERSION=	0.13.2.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	GTK2 Binding for Haskell

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

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
