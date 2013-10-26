# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	0.12.4
PORTREVISION=	5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the Webkit library

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	cairo>=0.12 glib>=0.12 gtk>=0.12 mtl pango>=0.12
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
