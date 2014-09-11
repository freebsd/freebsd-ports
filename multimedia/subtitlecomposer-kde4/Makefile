# $FreeBSD$

PORTNAME=	subtitlecomposer
PORTVERSION=	0.5.6
PORTREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	GITHUB

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor for KDE

LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu

USES=		cmake:outsource gettext shared-mime-info tar:bzip2
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build phonon

USE_GITHUB=	yes
GH_ACCOUNT=	maxrd2
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	74f2f04

OPTIONS_GROUP=	BACKEND
BACKEND_DESC=	Additional video backens
OPTIONS_GROUP_BACKEND=	GSTREAMER MPLAYER XINE

MPLAYER_DESC=	Install MPlayer
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

XINE_DESC=	Build Xine backend
XINE_LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine
XINE_CMAKE_OFF=	-DWITH_Xine:Bool=Off

GSTREAMER_DESC=	Build GStreamer backend
GSTREAMER_USE=	GSTREAMER=yes
GSTREAMER_CMAKE_OFF=	-DWITH_GStreamer:Bool=Off

.include <bsd.port.mk>
