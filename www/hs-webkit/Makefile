# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	0.13.1.3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Webkit library

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	cairo>=0.13.0.0 glib>=0.13.1.0 gtk>=0.13.0.0 mtl \
		pango>=0.13.0.0 text>=1.0.0.0
LIB_DEPENDS+=	libwebkitgtk-1.0.so:www/webkit-gtk2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
