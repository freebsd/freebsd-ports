# New ports collection makefile for:	subtitlecomposer
# Date created:		2008-01-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	subtitlecomposer
PORTVERSION=	0.5.3
PORTREVISION=	5
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/subcomposer/subcomposer/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor for KDE

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	gui qmake_build moc_build rcc_build uic_build

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=	GSTREAMER MPLAYER XINE
OPTIONS_DEFAULT=	MPLAYER

MPLAYER_DESC=	Enable MPlayer backend (recommended)
XINE_DESC=	Enable Xine backend
GSTREAMER_DESC=	Enable GStreamer backend (broken)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	xine.2:${PORTSDIR}/multimedia/libxine
.else
CMAKE_ARGS+=	-DWITH_Xine:Bool=Off
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
.else
CMAKE_ARGS+=	-DWITH_GStreamer:Bool=Off
.endif

.include <bsd.port.mk>
