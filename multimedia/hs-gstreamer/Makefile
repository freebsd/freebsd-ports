# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	0.12.5.0
PORTREVISION=	1
CATEGORIES=	multimedia haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GStreamer open source multimedia framework

LIB_DEPENDS=	libgstreamer-0.10.so:${PORTSDIR}/multimedia/gstreamer

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	glib>=0.12.5.0 mtl

BUILD_DEPENDS+=	gstreamer-plugins>=0.10:${PORTSDIR}/multimedia/gstreamer-plugins

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
