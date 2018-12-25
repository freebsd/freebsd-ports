# $FreeBSD$

PORTNAME=	subtitlecomposer
PORTVERSION=	0.5.7
DISTVERSIONPREFIX=	v
PORTREVISION=	15
CATEGORIES=	multimedia kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

CONFLICTS_INSTALL=	subtitlecomposer-*

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		cmake gettext kde:4 qt:4 shared-mime-info
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build rcc_build uic_build phonon
USE_CXXSTD=	gnu++98
CXXFLAGS+=	-DU_NOEXCEPT= # For USE_CXXSTD=gnu++98

USE_GITHUB=	yes
GH_ACCOUNT=	maxrd2

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
