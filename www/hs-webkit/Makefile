# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	0.12.6.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Webkit library

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	cairo>=0.12 glib>=0.12.1 gtk>=0.12.5.0 mtl pango>=0.12
LIB_DEPENDS+=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
