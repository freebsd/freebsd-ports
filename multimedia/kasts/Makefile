PORTNAME=	kasts
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE podcast app
WWW=		https://apps.kde.org/kasts/

LICENSE=	GPLv2+

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libtag.so:audio/taglib

USES=		cmake desktop-file-utils gettext gettext-runtime gnome \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	colorscheme config coreaddons crash dbusaddons i18n \
		iconthemes kirigami-addons kirigami2 syndication \
		threadweaver windowsystem \
		ecm:build
USE_QT=		base multimedia
USE_XORG=	x11

OPTIONS_MULTI=		AUDIO
AUDIO_DESC=		Audio backend
OPTIONS_MULTI_AUDIO=	GSTREAMER VLC
OPTIONS_DEFAULT=	GSTREAMER # VLC still uses Qt5

GSTREAMER_DESC=		Play audio via GStreamer
GSTREAMER_CMAKE_BOOL=	BUILD_GSTREAMER_BACKEND
GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=ogg,vorbis

VLC_DESC=		Play audio via libVLC
VLC_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LIBVLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

.include <bsd.port.mk>
