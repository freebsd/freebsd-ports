# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	0.12.1.2
PORTREVISION=	3
CATEGORIES=	multimedia haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GStreamer open source multimedia framework

LIB_DEPENDS=	gstreamer:${PORTSDIR}/multimedia/gstreamer

LICENSE=	LGPL21

USES=		pkgconfig
USE_CABAL=	glib>=0.12 mtl

BUILD_DEPENDS+=	gstreamer-plugins>=0.10:${PORTSDIR}/multimedia/gstreamer-plugins

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
