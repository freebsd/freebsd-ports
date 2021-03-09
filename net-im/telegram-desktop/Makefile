# $FreeBSD$

PORTNAME=	telegram-desktop
DISTVERSION=	2.6.1
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTNAME=	tdesktop-${DISTVERSION}-full
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Telegram Desktop messaging app

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	Does not build, webrtc related.
NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian is supported

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		dee>0:devel/dee \
		microsoft-gsl>0:devel/microsoft-gsl \
		pulseaudio>0:audio/pulseaudio \
		range-v3>0:devel/range-v3 \
		tl-expected>0:devel/tl-expected \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm \
		${LOCALBASE}/lib/libtg_owt.a:net-im/tg_owt
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libdbusmenu-qt5.so:devel/libdbusmenu-qt \
		libenchant-2.so:textproc/enchant2 \
		libhunspell-1.7.so:textproc/hunspell \
		libjpeg.so:graphics/jpeg-turbo \
		liblz4.so:archivers/liblz4 \
		libminizip.so:archivers/minizip \
		libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libqrcodegencpp.so:graphics/qr-code-generator \
		libusrsctp.so:net/libusrsctp \
		libxkbcommon.so:x11/libxkbcommon \
		libxxhash.so:devel/xxhash

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		gnome pkgconfig python:3.7,build qt:5 ssl xorg

USE_GITHUB=	nodefault
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
USE_GL=		gl
USE_GNOME=	glib20
INSTALLS_ICONS=	yes
USE_QT=		core dbus gui imageformats network widgets buildtools_build \
		qmake_build wayland
USE_XORG=	x11 xcb

CMAKE_ARGS=	-DDESKTOP_APP_SPECIAL_TARGET="" -DTDESKTOP_LAUNCHER_BASENAME="telegramdesktop" \
		-DTDESKTOP_API_ID=${TELEGRAM_API_ID} -DTDESKTOP_API_HASH=${TELEGRAM_API_HASH} \
		-Ddisable_autoupdate=1
CMAKE_ON=	DESKTOP_APP_USE_PACKAGED DESKTOP_APP_DISABLE_CRASH_REPORTS \
		TDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME TDESKTOP_DISABLE_DESKTOP_FILE_GENERATION \
		DESKTOP_APP_DISABLE_WAYLAND_INTEGRATION
CMAKE_OFF=	DESKTOP_APP_USE_PACKAGED_RLOTTIE DESKTOP_APP_USE_PACKAGED_VARIANT \
		DESKTOP_APP_USE_GLIBC_WRAPS TDESKTOP_USE_PACKAGED_TGVOIP \
		DESKTOP_APP_USE_PACKAGED_FONTS

# Disable DCHECKs, otherwise video calls will crash.
CXXFLAGS+=	-DNDEBUG

# see Bugzilla #245452 for details
NO_CCACHE=	yes

# Telegram uses OpenAL for its audio, but libtgvoip (for voice calls) can use PulseAudio or ALSA.
# It dynamically loads PulseAudio, and if this fails, it loads ALSA.
# If both of them are not installed, then voice calls do not work, but other functionalities still work.
OPTIONS_DEFINE=		GTK
OPTIONS_DEFAULT=	ALSA
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	ALSA PULSEAUDIO

AUDIO_DESC=	Audio backend for voice calls
GTK_DESC=	Gtk integration (Use Gtk dialogs, etc.)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
GTK_CMAKE_BOOL_OFF=	DESKTOP_APP_DISABLE_GTK_INTEGRATION
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

# Telegram asks each custom build to have its own API ID and hash.
TELEGRAM_API_HASH=	20a3432aab43f24bb4460fceac5ba38d
TELEGRAM_API_ID=	601761

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK}
USE_GNOME+=	gtk30
.endif

.include <bsd.port.mk>
