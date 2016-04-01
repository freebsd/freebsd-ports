# $FreeBSD$

PORTNAME=	subtitlecomposer
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	multimedia kde

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Subtitle editor for KDE

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		cmake:outsource gettext shared-mime-info
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build phonon

USE_GITHUB=	yes
GH_ACCOUNT=	maxrd2
GH_TAGNAME=	c73db78

OPTIONS_GROUP=	BACKEND
BACKEND_DESC=	Additional video backens
OPTIONS_GROUP_BACKEND=	GSTREAMER MPLAYER XINE

MPLAYER_DESC=	Install MPlayer
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer

XINE_DESC=	Build Xine backend
XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine
XINE_CMAKE_OFF=	-DWITH_Xine:Bool=Off

GSTREAMER_DESC=	Build GStreamer 1.x backend
GSTREAMER_USE=	GSTREAMER1=yes
GSTREAMER_CMAKE_OFF=	-DWITH_GStreamer:Bool=Off

post-patch:
	${REINPLACE_CMD} '/GStreamer/s,find_package,macro_optional_find_package,' \
		${WRKSRC}/src/services/CMakeLists.txt

.include <bsd.port.mk>
