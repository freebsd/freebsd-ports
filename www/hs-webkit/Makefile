# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	0.14.2.1
PORTREVISION=	4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Webkit library

LICENSE=	LGPL21

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=	2019-03-24

USES=		pkgconfig
USE_CABAL=	cairo>=0.13.0.0 glib>=0.13.1.0 gtk>=0.13.0.0 mtl \
		pango>=0.13.0.0
LIB_DEPENDS+=	libwebkitgtk-1.0.so:www/webkit-gtk2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
