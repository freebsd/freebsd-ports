# $FreeBSD$

PORTNAME=	gtk
PORTVERSION=	0.14.9
PORTREVISION=	2
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Gtk+ graphical user interface library

LICENSE=	LGPL21

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USES=		pkgconfig
USE_CABAL=	cairo>=0.13.0.0 gio>=0.13.0 glib>=0.13.0.0 mtl \
		pango>=0.13.0.0
USE_GNOME=	gtk20

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
