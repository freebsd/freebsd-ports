# New ports collection makefile for: hs-gstreamer
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.12.1.1
PORTREVISION=	1
CATEGORIES=	multimedia haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GStreamer open source multimedia framework

LIB_DEPENDS=	gstreamer:${PORTSDIR}/multimedia/gstreamer

LICENSE=	LGPL21
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs
USE_CABAL=	glib>=0.12 mtl

BUILD_DEPENDS+=	gstreamer-plugins>=0.10:${PORTSDIR}/multimedia/gstreamer-plugins

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
