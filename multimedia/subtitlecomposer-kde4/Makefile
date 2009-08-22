# New ports collection makefile for:	subtitlecomposer
# Date created:		2008-01-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	subtitlecomposer
PORTVERSION=	0.5.3
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/subcomposer/subcomposer/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor for KDE

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build rcc_build uic_build
WANT_GSTREAMER=	yes

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS=	MPLAYER "Enable MPlayer backend (recommended)" on \
		XINE "Enable Xine backend" off \
		GSTREAMER "Enable GStreamer backend (broken)" off

.include <bsd.port.pre.mk>

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
.else
CMAKE_ARGS+=	-DWITH_Xine:Bool=Off
.endif

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	yes
.else
CMAKE_ARGS+=	-DWITH_GStreamer:Bool=Off
.endif

.include <bsd.port.post.mk>
