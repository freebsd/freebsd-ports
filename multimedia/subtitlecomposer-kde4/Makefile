# $FreeBSD$

PORTNAME=	subtitlecomposer
PORTVERSION=	0.5.3
PORTREVISION=	5
CATEGORIES=	multimedia kde
MASTER_SITES=	SF/subcomposer/subcomposer/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor for KDE

USE_BZIP2=	yes
USES=		cmake:outsource gettext
USE_KDE4=	kdeprefix kdelibs automoc4 sharedmime
USE_QT4=	qmake_build moc_build rcc_build uic_build phonon

OPTIONS_GROUP=	BACKEND
BACKEND_DESC=	Additional video backens
OPTIONS_GROUP_BACKEND=	GSTREAMER MPLAYER XINE

MPLAYER_DESC=	Install MPlayer
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

XINE_DESC=	Build Xine backend
XINE_LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine
XINE_CMAKE_OFF=	-DWITH_Xine:Bool=Off

GSTREAMER_DESC=	Build GStreamer backend (broken)
GSTREAMER_USE=	GSTREAMER=yes
GSTREAMER_CMAKE_OFF=	-DWITH_GStreamer:Bool=Off

.include <bsd.port.mk>
