# $FreeBSD$

PORTNAME=	gtksourceview2
PORTVERSION=	0.13.3.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GtkSourceView library

LICENSE=	LGPL21

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USES=		pkgconfig
USE_CABAL=	glib>=0.13 gtk>=0.13.0.0 mtl
USE_GNOME=	gtksourceview2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
